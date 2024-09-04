/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbar <inbar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:17:59 by inbar             #+#    #+#             */
/*   Updated: 2024/09/04 12:39:26 by inbar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//finds for every node in a, target node in b
//target node is the node to be under the new pushed node
//if new pushed is a new max or min in stack, target is old max
//else target is biggest smallest number of new pushed
void	find_target(t_stack **a, t_stack **b)
{
	t_stack *node;
	t_stack	*tmp;
	t_stack	*potential;

	if (!*b || !b)
		return ;
	node = *a;
	while(node != NULL)
	{
		tmp = *b;
		potential = find_min(b);
		if (node->value < potential->value) // smallest value
			node->target = find_max(b);
		else
		{
			while (tmp != NULL)
			{
				if (node->value > tmp->value && tmp->value > potential->value)
					potential = tmp;
				tmp = tmp->next;
			}
			node->target = potential;
		}
		node = node->next;
	}
}

//setting index of node and if below or above median
void	set_index(t_stack **a)
{
	t_stack	*tmp;
	int		index;
	int		median;

	index = 0;
	if (!a || !*a)
		return ;
	median = lstsize(a) / 2;
	tmp = *a;
	while (tmp)
	{
		tmp->index = index;
		tmp->below_median = 0;
		if (index <= median)
			tmp->below_median = 1;
		index++;
		tmp = tmp->next;
	}
}

//set push price for all nodes on given stack. target_node must be set
void	find_push_price(t_stack **a)
{
	(void)a;
}