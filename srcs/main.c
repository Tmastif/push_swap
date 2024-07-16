/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:07:52 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/15 21:54:21 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void);
int		verify_input(int ac, char **arg);

/*
• If no parameters are specified,
	the program must not display anything and give the
prompt back.
• In case of error,
	it must display "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers,
	some arguments are
bigger than an integer and/or there are duplicates.
*/
int	main(int ac, char **av)
{
	int	*arg;

	arg = (int *)malloc(sizeof(int) * ac);
	if (ac > 1)
	{
		if (verfiy_atoi(ac, av, &arg))
		{
			printf("valid input\n"); // start_program();
			print_arr()
		}
		else
			error();
	}
	return (0);
}

int	verfiy_atoi(int ac, char **av, int *arg)
{
	long	nbr;
	int		sign;
	int		j;

	av[ac] = NULL;
	ac = 1;
	while (av[ac])
	{
		sign = 1;
		nbr = 0;
		j = 0;
		if (av[ac][j] == '-')
		{
			sign = -1;
			j++;
		}
		while (av[ac][j] != '\0')
		{
			if (!ft_isdigit(av[ac][j]))
				return (0);
			nbr = (nbr * 10) + av[ac][j] - '0';
			j++;
		}
		arg[ac - 1] = nbr * sign;
		ac++;
	}
	return (1);
}

// if (nbr > MAX_INT || nbr < MIN_INT)
// 	return (0);
int	verify_input(int ac, char **arg)
{
	int	j;

	arg[ac] = NULL;
	ac = 1;
	while (arg[ac])
	{
		j = 0;
		if (arg[ac][j] == '-') // ignore minus sign in av[ac][j]
			j++;
		while (arg[ac][j] != '\0')
		{
			if (!ft_isdigit(arg[ac][j])) // check all are digits
				return (0);
			j++;
		}
		ac++;
	}
	return (1);
}

void	error(void)
{
	ft_printf("Error\n");
}