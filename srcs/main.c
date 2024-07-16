/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:07:52 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/16 19:24:14 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	input_error(char **av, int to_free);
// void	print_it(char **arr);
void	build_a(t_stack *a, char **str, int to_free);
long	verify_atol(char **av, int i, int to_free);

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
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac > 1) // more than prog name
	{
		if (ac == 2 && av[1][0] != '\0') // if string not empty
			av = ft_split(av[1], ' ');
		else
		{
			av[ac] = NULL;
			av++;
		}
		build_a(a, av, ac == 2);
		// print_it(av);
	}
	return (0);
}

/* str may be freeable or not
check for
		not a number
		< > max min int
		duplicate

		if number
		if range of int

		if list have nodes
		if no node of same value
		create new node
	*/

void	build_a(t_stack *a, char **av, int to_free)
{
	long	nbr;
	int		i;
	t_stack	*node;

	i = 0;
	// printf("########## free: %d\n", to_free);
	while (av[i])
	{
		nbr = verify_atol(av, i, to_free);
		if (nbr < INT_MIN || nbr > INT_MAX)
			input_error(av, to_free);
		if (found_duplicate(a, (int)nbr))
			input_error(av, to_free);
		node = create_node((int)nbr);
		if (node == NULL)
			malloc_error();
		addbottom_node(&a, node);
		i++;
	}
	print_list(a);
	free_array(av, to_free);
	destroy_lst(&a);
}

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

long	verify_atol(char **av, int i, int to_free)
{
	int sign;
	char *str;
	long nbr;

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
			input_error(av, to_free);
		nbr = (nbr * 10) + str[i++] - '0';
	}
	return (nbr * sign);
}