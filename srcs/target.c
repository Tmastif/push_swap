/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:17:59 by inbar             #+#    #+#             */
/*   Updated: 2024/07/26 18:54:58 by ilazar           ###   ########.fr       */
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
	t_stack *tmp;
	int index;

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