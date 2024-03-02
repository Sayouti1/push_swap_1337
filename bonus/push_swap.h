/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sayo <aes-sayo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 02:52:50 by aes-sayo          #+#    #+#             */
/*   Updated: 2024/01/24 02:52:52 by aes-sayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

/*_______________________stack_functions________________________________*/

t_stack				*ft_new_node(int value);
void				ft_push_node(t_stack **stack_x, t_stack *node);
t_stack				*ft_last(t_stack *stack_x);
size_t				ft_stack_len(t_stack *stack_x);

/*_______________________subject_functions______________________________*/

void				ft_pa(t_stack **a, t_stack **b, int	out);
void				ft_pb(t_stack **a, t_stack **b, int	out);
void				ft_sa(t_stack **a, int	out);
void				ft_sb(t_stack **b, int	out);
void				ft_ss(t_stack **a, t_stack **b, int	out);
void				ft_ra(t_stack **a, int	out);
void				ft_rb(t_stack **b, int	out);
void				ft_rr(t_stack **a, t_stack **b, int	out);
void				ft_rra(t_stack **a, int	out);
void				ft_rrb(t_stack **b, int	out);
void				ft_rrr(t_stack **a, t_stack **b, int	out);

/*________________________stack_methods_________________________________*/

void				ft_swap(t_stack **stack_a);
void				ft_push(t_stack **from, t_stack **to);
void				ft_rotate(t_stack **stack_x);
void				ft_reverse_rotate(t_stack **stack_x);

/*________________________getters_______________________________________*/

int					ft_init_stack(t_stack **a, char **tab, int from_argv);

/*_________________________check_functions______________________________*/
int					ft_is_sorted(t_stack *stack_x);
int					ft_is_duplicated(t_stack *a);
int					ft_check_error(char **str);

/*_________________________________new_algo.c___________________________*/

void				ft_checker(t_stack **a, t_stack **b);

/*_________________________________utils________________________________*/

long				ft_atol(char *str);
void				free_stack(t_stack **a);

#endif
