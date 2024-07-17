/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:51:50 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/17 18:27:40 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap first 2 elements
void	swap_stk(t_stack **stk)
{
	t_stack	*tmp;

	// t_stack	*first_node;
	// t_stack	*second_node;
	if (!stk || !*stk)
		return ;
	if ((*stk)->next == NULL)
		return ;
	// tmp = *stk;
	// first_node = tmp;
	// second_node = tmp->next;
	// printf("first node: %d\n", tmp->value);
	// printf("2nd node: %d\n", second_node->value);
	// // printf("tmp node: %d\n", tmp);
	// // first = second
	// first_node->next = second_node->next;
	// first_node->prev = NULL;
	// *first_node = *second_node;
	// // second = first;
	// second_node->next = tmp->next;
	// second_node->prev = tmp->prev;
	// *second_node = *tmp;
	tmp = *stk;
	*stk = (*stk)->next;
	(*stk)->next = tmp;
}
/*
void	push_stk(t_stack **stk)
{
}

void	rotate_stk(t_stack **stk)
{
}

void	rev_rotate_stk(t_stack **stk)
{
}
*/