/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:38:18 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/18 17:45:02 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap first 2 elements
static void	swap_stk(t_stack **stk)
{
	t_stack	*second;
	int		tmp;

	if (!stk || !*stk)
		return ;
	if ((*stk)->next == NULL)
		return ;
	second = (*stk)->next;
	tmp = (*stk)->value;
	(*stk)->value = second->value;
	second->value = tmp;
}

void	swap_a(t_stack **a)
{
	swap_stk(a);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **b)
{
	{
		swap_stk(b);
		write(1, "sb\n", 3);
	}
}
void	swap_ss(t_stack **a, t_stack **b)
{
	swap_stk(a);
	swap_stk(b);
	write(1, "ss\n", 3);
}
