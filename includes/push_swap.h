/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilazar <ilazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:04:58 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/17 14:06:42 by ilazar           ###   ########.fr       */
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

// list init
void				build_a(t_stack **a, char **str, int to_free);
long				verify_atol(t_stack **a, char **av, int i, int to_free);
int					found_duplicate(t_stack *a, int nbr);
void				free_array(char **av, int to_free);

// stack commands
void				swap_stk(t_stack **stk);

// error utils
void				input_error(t_stack **a, char **av, int to_free);
void				print_it(char **arr);
void				malloc_error(void);

// list commands
t_stack				*create_node(int nbr);
void				print_list(t_stack *a);
void				*addbottom_node(t_stack **begin, t_stack *node);
t_stack				*lstlast(t_stack *begin);
void				destroy_lst(t_stack **a);

// errors
void				malloc_error(void);

#endif
