/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:46:40 by ilazar            #+#    #+#             */
/*   Updated: 2024/09/04 18:31:20 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_together(t_stack **a, t_stack **b, t_stack *cheapest);

// returns the node with lowest push_price
t_stack	*get_cheapest(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*cheapest;

	if (!a || !*a)
		return (NULL);
	cheapest = *a;
	tmp = *a;
	while (tmp)
	{
		if (tmp->push_price < cheapest->push_price)
			cheapest = tmp;
		tmp = tmp->next;
	}
	printf("chepeast: %d target: %d\n", cheapest->value,
		cheapest->target->value);
	return (cheapest);
}

void	move_nodes(t_stack **a, t_stack **b, t_stack *cheapest)
{
	if (!a || !b || !*a || !*b || !cheapest)
		return ;
	if (*a != cheapest && *b != cheapest->target)
		rotate_together(a, b, cheapest);
	while (*a != cheapest)
	{
		if (cheapest->upper_half == 1)
			ro_a(a);
		else
			revro_a(a);
	}
	while (*b != cheapest->target)
	{
		if (cheapest->target->upper_half == 1)
			ro_b(b);
		else
			revro_b(b);
	}
	push_b(a, b);
}

static void	rotate_together(t_stack **a, t_stack **b, t_stack *cheapest)
{
	if (cheapest->upper_half == cheapest->target->upper_half)
		while (*a != cheapest || *b != cheapest->target)
		{
			if (cheapest->upper_half == 1)
				ro_ab(a, b);
			else
				revro_ab(a, b);
		}
}