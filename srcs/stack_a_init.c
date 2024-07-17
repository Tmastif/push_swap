/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bulid_stacka.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:47:07 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/17 14:13:37 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 0 if list empty or no duplicate value found. 1 otherwise
int	found_duplicate(t_stack *a, int nbr)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp != NULL)
	{
		if (tmp->value == nbr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

long	verify_atol(t_stack **a, char **av, int i, int to_free)
{
	int		sign;
	char	*str;
	long	nbr;

	str = av[i];
	sign = 1;
	i = 0;
	nbr = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			input_error(a, av, to_free);
		nbr = (nbr * 10) + str[i++] - '0';
	}
	return (nbr * sign);
}

void	build_a(t_stack **a, char **av, int to_free)
{
	long	nbr;
	int		i;
	t_stack	*node;

	i = 0;
	while (av[i])
	{
		nbr = verify_atol(a, av, i, to_free);
		if (nbr < INT_MIN || nbr > INT_MAX || found_duplicate(*a, (int)nbr))
			input_error(a, av, to_free);
		node = create_node((int)nbr);
		if (node == NULL)
			malloc_error();
		addbottom_node(a, node);
		i++;
	}
	free_array(av, to_free);
}

void	free_array(char **av, int to_free)
{
	int i;

	i = 0;
	if (to_free)
	{
		while (av[i] != NULL)
			free(av[i++]);
		free(av);
	}
}