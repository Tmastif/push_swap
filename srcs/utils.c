/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:15:38 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/16 19:23:58 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **av, int to_free)
{
	int	i;

	i = 0;
	if (to_free)
		while (av[i] != NULL)
			free(av[i++]);
	free(av);
}

void	input_error(char **av, int to_free)
{
	ft_printf("Error\n");
	free_array(av, to_free);
	free(av);
	exit(2);
}

void	print_it(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		printf("%s\n", arr[i++]);
	}
}

void	malloc_error(void)
{
	printf("malloc error\n");
	exit(1);
}