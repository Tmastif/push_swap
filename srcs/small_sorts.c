/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbar <inbar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:58:06 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/25 16:24:45 by inbar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *find_max(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*max;

	if (a == NULL || *a == NULL)
		return (NULL);
	tmp = *a;
	max = tmp;
	while (tmp)
	{
		if (max->value < tmp->value)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_stack	*find_min(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*min;

	if (a == NULL || *a == NULL)
		return (NULL);
	tmp = *a;
	min = tmp;
	while (tmp)
	{
		if (min->value > tmp->value)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
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
	t_stack *max;
	t_stack *tmp;

	max = find_max(a);
	if (max == *a) // if max is first bring max to bottom
		ro_a(a);
	tmp = (*a)->next;
	if (tmp == max)
		revro_a(a); // if max is 2nd bring max to bottom
	tmp = (*a)->next;
	if ((*a)->value > tmp->value)
		swap_a(a);
}