/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbar <inbar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:17:59 by inbar             #+#    #+#             */
/*   Updated: 2024/07/25 14:38:23 by inbar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    find_target(t_stack *node, t_stack **b)
{
    t_stack *tmp;
    t_stack *potential;

    if (!node || !*b || !b)
        return ;
    tmp = *b;
    node->target = *b;
    potential = node->target;
    while (tmp != NULL)
    {
        if (node->value > tmp->value && tmp->value < potential->value)
           potential = tmp;
        tmp = tmp->next;
    }
    node->target = potential;
}