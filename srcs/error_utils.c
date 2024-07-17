/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:15:38 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/17 13:49:12 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_error(t_stack **a, char **av, int to_free)
{
	ft_printf("Error\n");
	free_array(av, to_free);
	destroy_lst(a);
	exit(2);
}

void	malloc_error(void)
{
	printf("malloc error\n");
	exit(1);
}
// print array
void	print_it(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
	{
		printf("%s\n", arr[i++]);
	}
}