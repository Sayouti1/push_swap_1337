/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subject_methods_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sayo <aes-sayo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 02:15:26 by aes-sayo          #+#    #+#             */
/*   Updated: 2024/01/24 02:15:35 by aes-sayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **a, int out)
{
	ft_rotate(a);
	if (out)
		ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stack **b, int out)
{
	ft_rotate(b);
	if (out)
		ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stack **a, t_stack **b, int out)
{
	ft_rotate(a);
	ft_rotate(b);
	if (out)
		ft_putstr_fd("rr\n", 1);
}

void	ft_rra(t_stack **a, int out)
{
	ft_reverse_rotate(a);
	if (out)
		ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stack **b, int out)
{
	ft_reverse_rotate(b);
	if (out)
		ft_putstr_fd("rrb\n", 1);
}
