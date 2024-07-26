/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:07:52 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/26 19:47:07 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*tmp;

	a = NULL;
	b = NULL;
	if (ac > 1) // more than prog name
	{
		if (av[1][0] == '\0')
			input_error(&a, av, 0);
		if (ac == 2)
			av = ft_split(av[1], ' ');
		else
		{
			av[ac] = NULL;
			av++;
		}
		build_a(&a, av, ac == 2);
		// printf("max: %d\n", find_max(&a));
		// printf("size: %d\n", lstsize(&a));
		push_b(&a, &b);
		push_b(&a, &b);
		push_b(&a, &b);
		print_ab(a, b);
		printf("find targ:et of *a\n");
		find_target(a, &b);
		printf("target value of: %d is %d\n", (*a).value, (*a).target->value);
		tmp = a;
		set_index(&a);
		while (tmp)
		{
			printf("index of %d, is: %d\n", tmp->value, tmp->index);
			tmp = tmp->next;
		}
		find_push_price(a, &a, &b);
		// destroy_lst(&b);
	}
	return (0);
}
