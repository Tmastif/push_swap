/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:17:59 by inbar             #+#    #+#             */
/*   Updated: 2024/09/04 17:17:56 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_self_price(t_stack *node, int stksize);
static int	find_target_price(t_stack *node, int stksize);

// finds for every node in a, target node in b
// target node is the node to be under the new pushed node
// if new pushed is a new max or min in stack, target is old max
// else target is biggest smallest number of new pushed
void	find_target(t_stack **a, t_stack **b)
{
	t_stack	*node;
	t_stack	*tmp;
	t_stack	*potential;

	if (!*b || !b)
		return ;
	node = *a;
	while (node != NULL)
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

// setting index of node and if below or above median
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
		tmp->upper_half = 0;
		if (index <= median)
			tmp->upper_half = 1;
		index++;
		tmp = tmp->next;
	}
}

// set push price for all nodes on given stack. target_node must be set
void	find_push_price(t_stack **a, t_stack **b)
{
	t_stack	*node;
	int		stksize_a;
	int		stksize_b;
	int		self_price;
	int		target_price;

	if (!a || !*a)
		return ;
	stksize_a = lstsize(a);
	stksize_b = lstsize(b);
	node = *a;
	while (node)
	{
		self_price = find_self_price(node, stksize_a);
		target_price = find_target_price(node, stksize_b);
		node->push_price = self_price + target_price;
		if ((*node).target->upper_half == node->upper_half)
		{
			if (self_price > target_price)
				node->push_price = self_price;
			else
				node->push_price = target_price;
		}
		node = node->next;
	}
}

static int	find_target_price(t_stack *node, int stksize)
{
	int	target_price;

	target_price = 0;
	if (node->target)
	{
		target_price = node->target->index;
		if (node->target->upper_half == 0)
			target_price = stksize - target_price;
	}
	return (target_price);
}

static int	find_self_price(t_stack *node, int stksize)
{
	int	self_price;

	self_price = 0;
	if (node)
	{
		self_price = node->index;
		if (node->upper_half == 0)
			self_price = stksize - self_price;
	}
	return (self_price);
}
