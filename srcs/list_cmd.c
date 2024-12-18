/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:30:39 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/18 16:57:03 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = nbr;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
t_stack	*lstlast(t_stack *begin)
{
	if (begin == NULL)
		return (NULL);
	while (begin->next != NULL)
		begin = begin->next;
	return (begin);
}

t_stack	*addbottom_node(t_stack **begin, t_stack *node)
{
	t_stack	*tmp;

	if (begin == NULL)
		return (NULL);
	if (*begin == NULL)
		*begin = node;
	else
	{
		tmp = lstlast(*begin);
		tmp->next = node;
		node->prev = tmp;
	}
	return (node);
}

void	destroy_lst(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!a)
		return ;
	current = *a;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

void	print_list(t_stack *a, char c)
{
	t_stack	*tmp;

	if (a == NULL)
	{
		ft_printf("----%c\n null\n----%c\n", c, c);
		return ;
	}
	tmp = a;
	ft_printf("----%c\n", c);
	while (tmp != NULL)
	{
		ft_printf(" %d   		", tmp->value);
		if ((*tmp).next)
			ft_printf("next: %d     ", (*tmp).next->value);
		else
			ft_printf("next: Null     ");
		if ((*tmp).prev)
			ft_printf("prev: %d\n", (*tmp).prev->value);
		else
			ft_printf("prev: Null\n");
		tmp = tmp->next;
	}
	ft_printf("----%c\n", c);
}
