/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:58:06 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/24 17:02:27 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack **a)
{
	t_stack	*tmp;
	int		max;

	if (a == NULL || *a == NULL)
		return (-1);
	tmp = *a;
	max = tmp->value;
	while (tmp)
	{
		if (max < tmp->value)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}
int	lstsize(t_stack **a)
{
	t_stack	*tmp;
	int		size;

	size = 0;
	if (a == NULL || *a == NULL)
		return (-1);
	tmp = *a;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	three_sort(t_stack **a)
{
	// biggest at the bottom
	// swap two others if bigger of the two is above
	int max;
	t_stack *tmp;

	max = find_max(a);
	if (max == (*a)->value) // if max is first bring max to bottom
		ro_a(a);
	tmp = (*a)->next;
	if (tmp->value == max)
		revro_a(a); // if max is 2nd bring max to bottom
	tmp = (*a)->next;
	if ((*a)->value > tmp->value)
		swap_a(a);
}