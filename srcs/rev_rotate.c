/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:52:41 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/18 18:02:44 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate_stk(t_stack **stk)
{
	t_stack	*head;
	t_stack	*tail;

	if (!stk || !*stk)
		return ;
	if ((*stk)->next == NULL)
		return ;
	tail = lstlast(*stk);
	head = *stk;
	*stk = tail;
	tail->next = head;
	tail->prev->next = NULL;
	tail->prev = NULL;
	head->prev = tail;
}

void	revro_a(t_stack **a)
{
	rev_rotate_stk(a);
	write(1, "rra\n", 4);
}
void	revro_b(t_stack **b)
{
	rev_rotate_stk(b);
	write(1, "rrb\n", 4);
}

void	revro_ab(t_stack **a, t_stack **b)
{
	rev_rotate_stk(a);
	rev_rotate_stk(b);
	write(1, "rrr\n", 4);
}
