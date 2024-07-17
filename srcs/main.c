/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:07:52 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/17 17:34:53 by ilazar           ###   ########.fr       */
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
		print_list(a);
		printf("doing a swap:\n");
		swap_stk(&a);
		print_list(a);
		destroy_lst(&a);
	}
	return (0);
}
