/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:25:22 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/18 17:41:49 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_list(t_stack *a, char c)
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

void	print_a(t_stack *a)
{
	print_list(a, 'a');
}

void	print_b(t_stack *a)
{
	print_list(a, 'b');
}
void	print_ab(t_stack *a, t_stack *b)
{
	print_list(a, 'a');
	print_list(b, 'b');
}
