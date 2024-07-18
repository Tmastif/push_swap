/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:07:52 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/18 18:04:46 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

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
		print_a(a);
		push_b(&a, &b);
		swap_a(&a);
		swap_b(&b);
		print_ab(a, b);
		destroy_lst(&a);
	}
	return (0);
}
