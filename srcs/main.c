/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbar <inbar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:07:52 by ilazar            #+#    #+#             */
/*   Updated: 2024/09/04 14:55:53 by inbar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	print_targets(t_stack *a);
void 	print_prices(t_stack *a);

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	//t_stack	*tmp;

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
		set_index(&a);
		set_index(&b);
		find_target(&a, &b);
		print_targets(a);
		find_push_price(&a, &b);
		print_prices(a);
		print_ab(a, b);
		// destroy_lst(&b);
	}
	return (0);
}

void 	print_prices(t_stack *a)
{
	t_stack *tmp;

	if (!a)
		return ;
	tmp = a;
	while (tmp)
	{
		printf("price of %d is %d$\n", tmp->value, tmp->push_price);
		//printf("tmp->next: %d \n", tmp->next->value);
		tmp = tmp->next;
	}
}

void 	print_targets(t_stack *a)
{
	t_stack *tmp;

	if (!a)
		return ;
	tmp = a;
	while (tmp)
	{
		printf("target of %d ---> %d\n", tmp->value, (*tmp).target->value);
		//printf("tmp->next: %d \n", tmp->next->value);
		tmp = tmp->next;
	}
}