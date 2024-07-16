/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:04:58 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/16 19:24:31 by ilazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// utils
void				input_error(char **av, int to_free);
void				print_it(char **arr);
void				free_array(char **av, int to_free);

//
int					found_duplicate(t_stack *a, int nbr);

// list commands
t_stack				*create_node(int nbr);
void				print_list(t_stack *a);
void				*addbottom_node(t_stack **begin, t_stack *node);
t_stack				*lstlast(t_stack *begin);
void				destroy_lst(t_stack **a);

// errors
void				malloc_error(void);

#endif
