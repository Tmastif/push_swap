/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:07:52 by ilazar            #+#    #+#             */
/*   Updated: 2024/09/05 20:07:02 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_targets(t_stack *a);
void	print_prices(t_stack *a);
void	push_swap(t_stack **a, t_stack **b);

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
		if (!is_sorted(&a))
			push_swap(&a, &b);
		// print_ab(a, b);
		destroy_lst(&a);
		destroy_lst(&b);
	}
	return (0);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int		a_size;
	t_stack	*tmp;

	a_size = lstsize(a);
	if (a_size < 3)
	{
		min_to_top(a);
		return ;
	}
	if (a_size == 3)
	{
		three_sort(a);
		return ;
	}
	push_b(a, b);
	push_b(a, b);
	a_size -= 2;
	while (a_size > 3)
	{
		// print_ab(*a, *b);
		set_index(a);
		set_index(b);
		find_target(a, b);
		find_push_price(a, b);
		tmp = get_cheapest(a);
		move_nodes_b(a, b, tmp);
		a_size--;
	}
	// printf("3 sort:\n");
	three_sort(a);
	return_nodes_a(a, b);
}

void	print_prices(t_stack *a)
{
	t_stack	*tmp;

	if (!a)
		return ;
	tmp = a;
	while (tmp)
	{
		printf("price of %d is %d$\n", tmp->value, tmp->push_price);
		// printf("tmp->next: %d \n", tmp->next->value);
		tmp = tmp->next;
	}
}

void	print_targets(t_stack *a)
{
	t_stack *tmp;

	if (!a)
		return ;
	tmp = a;
	while (tmp)
	{
		printf("target of %d ---> %d\n", tmp->value, (*tmp).target->value);
		// printf("tmp->next: %d \n", tmp->next->value);
		tmp = tmp->next;
	}
}