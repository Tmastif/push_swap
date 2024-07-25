/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbar <inbar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:04:58 by ilazar            #+#    #+#             */
/*   Updated: 2024/07/25 16:25:22 by inbar            ###   ########.fr       */
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
	struct s_stack	*target;
}					t_stack;

//target
void    find_target(t_stack *node, t_stack **b);

// small sort
t_stack				*find_max(t_stack **a);
t_stack				*find_min(t_stack **a);
int					lstsize(t_stack **a);
void				three_sort(t_stack **a);

// list init
void				build_a(t_stack **a, char **str, int to_free);
long				verify_atol(t_stack **a, char **av, int i, int to_free);
int					found_duplicate(t_stack *a, int nbr);
void				free_array(char **av, int to_free);

// swap
void				swap_a(t_stack **a);
void				swap_b(t_stack **b);
void				swap_ss(t_stack **a, t_stack **b);

// push
void				push_a(t_stack **a, t_stack **b);
void				push_b(t_stack **a, t_stack **b);

// rotate
void				ro_a(t_stack **a);
void				ro_b(t_stack **b);
void				ro_ab(t_stack **a, t_stack **b);

// rev rotate
void				revro_a(t_stack **a);
void				revro_b(t_stack **b);
void				revro_ab(t_stack **a, t_stack **b);

// error utils
void				input_error(t_stack **a, char **av, int to_free);
void				print_it(char **arr);
void				malloc_error(void);

// list commands
t_stack				*create_node(int nbr);
t_stack				*addbottom_node(t_stack **begin, t_stack *node);
t_stack				*lstlast(t_stack *begin);
void				destroy_lst(t_stack **a);

// errors
void				malloc_error(void);

// print
void				print_ab(t_stack *a, t_stack *b);
void				print_a(t_stack *a);
void				print_b(t_stack *a);

#endif
