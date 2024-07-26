/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:17:59 by inbar             #+#    #+#             */
/*   Updated: 2024/07/26 19:47:43 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target(t_stack *node, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*potential;

	if (!node || !*b || !b)
		return ;
	tmp = *b;
	node->target = *b;
	potential = find_min(b);
	if (node->value < potential->value) // smallest value
	{
		node->target = find_max(b);
		return ;
	}
	while (tmp != NULL)
	{
		if (node->value > tmp->value && tmp->value > potential->value)
			potential = tmp;
		tmp = tmp->next;
	}
	node->target = potential;
}

void	set_index(t_stack **a)
{
	t_stack	*tmp;
	int		index;

	index = 0;
	if (!a || !*a)
		return ;
	tmp = *a;
	while (tmp)
	{
		tmp->index = index;
		index++;
		tmp = tmp->next;
	}
}

void	find_push_price(t_stack *node, t_stack **a, t_stack **b)
{
	int median;
	int stk_a_size;
	int stk_b_size;

	(void)node;

	stk_a_size = lstsize(a);
	stk_b_size = lstsize(b);

	median = stk_a_size / 2;
	printf("stk a size: %d  stk b size: %d  median a: %d\n", stk_a_size,
		stk_b_size, median);
}