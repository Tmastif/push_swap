/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:51:50 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/18 17:51:09 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_stk_next(t_stack **src, t_stack **target);

void	rotate_stk(t_stack **stk, char ab)
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
	write(1, "r", 1);
	write(1, &ab, 1);
	write(1, "\n", 1);
}

void	rev_rotate_stk(t_stack **stk, char ab)
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
	write(1, "rr", 2);
	write(1, &ab, 1);
	write(1, "\n", 1);
}

static void	push_stk(t_stack **src, t_stack **target)
{
	t_stack	*node;

	if (!src || !*src) // a is empty
		return ;
	node = *src;
	if (*target == NULL) // b is empty
	{
		*target = node;
		*src = node->next;
		if (node->next) // is src stack have more elem
			node->next->prev = NULL;
		node->next = NULL;
	}
	else
		push_stk_next(src, target);
}

// when target isnt empty
static void	push_stk_next(t_stack **src, t_stack **target)
{
	t_stack	*node;

	node = *src;
	(*target)->prev = node;
	if (node->next) // src has more than 2
	{
		node->next->prev = NULL; // Src stack new 1st node prev = null
		*src = node->next;
		node->next = *target;
		*target = node;
	}
	else
	{ // src has only one elem
		node->next = *target;
		*target = node;
		*src = NULL;
	}
}

void	push_a(t_stack **a, t_stack **b)
{
	push_stk(b, a);
	write(1, "pa\n", 3);
}
void	push_b(t_stack **a, t_stack **b)
{
	push_stk(a, b);
	write(1, "pb\n", 3);
}