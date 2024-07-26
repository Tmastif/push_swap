/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:46:40 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/26 18:49:28 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack **a)
{
	t_stack *tmp;
	int index;

	index = 0;
	if (!a || !*a)
		return ;
	tmp = *a;
	while (*tmp)
	{
		tmp->index = index;
		index++;
		tmp = tmp->next;
	}
}