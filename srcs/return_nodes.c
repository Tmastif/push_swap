/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:35:35 by ilazar            #+#    #+#             */
/*   Updated: 2024/09/05 20:07:03 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_return_target(t_stack **a, t_stack *top_b);
static void		bring_to_top(t_stack **a, t_stack *target);

void	return_nodes_a(t_stack **a, t_stack **b)
{
	t_stack	*top_b;
	t_stack	*target;
	int		b_size;

	if (!a || !b || !*a || !*b)
		return ;
	b_size = lstsize(b);
	while (b_size > 0)
	{
		top_b = *b;
		target = find_return_target(a, top_b);
		bring_to_top(a, target);
		push_a(a, b);
		b_size--;
	}
	min_to_top(a);
}

// return target is nearest biggest. for ex. the target of 8 is 9
// if tob_b is new max, target is the minimum of a
static t_stack	*find_return_target(t_stack **a, t_stack *top_b)
{
	t_stack	*tmp;
	t_stack	*target;

	if (!a || !*a || !top_b)
		return (NULL);
	tmp = *a;
	target = find_max(a);
	if (top_b->value > target->value)
		return (find_min(a));
	while (tmp)
	{
		if (tmp->value > top_b->value && tmp->value < target->value)
			target = tmp;
		tmp = tmp->next;
	}
	return (target);
}

static void	bring_to_top(t_stack **a, t_stack *target)
{
	if (!a || !*a || !target)
		return ;
	set_index(a);
	while (*a != target)
	{
		if (target->upper_half == 1)
			ro_a(a);
		else
			revro_a(a);
	}
}
void	min_to_top(t_stack **a)
{
	t_stack *min;

	if (!a || !*a)
		return ;
	set_index(a);
	min = find_min(a);
	while (*a != min)
	{
		if (min->upper_half == 1)
			ro_a(a);
		else
			revro_a(a);
	}
}