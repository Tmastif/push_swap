/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:58:08 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/18 18:03:22 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stk(t_stack **stk)
{
	t_stack	*head;
	t_stack	*tail;

	if (!stk || !*stk)
		return ;
	if ((*stk)->next == NULL)
		return ;
	tail = lstlast(*stk);
	head = *stk;
	*stk = head->next;
	head->next = NULL;
	head->prev = tail;
	tail->next = head;
	(*stk)->prev = NULL;
}

void	ro_a(t_stack **a)
{
	rotate_stk(a);
	write(1, "ra\n", 3);
}

void	ro_b(t_stack **b)
{
	rotate_stk(b);
	write(1, "rb\n", 3);
}

void	ro_ab(t_stack **a, t_stack **b)
{
	rotate_stk(a);
	rotate_stk(b);
	write(1, "rr\n", 3);
}
