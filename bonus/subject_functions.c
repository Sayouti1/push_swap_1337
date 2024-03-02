/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subject_methods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sayo <aes-sayo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 02:14:04 by aes-sayo          #+#    #+#             */
/*   Updated: 2024/01/24 02:14:20 by aes-sayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a, int out)
{
	ft_swap(a);
	if (out)
		ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack **b, int out)
{
	ft_swap(b);
	if (out)
		ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stack **a, t_stack **b, int out)
{
	ft_swap(a);
	ft_swap(b);
	if (out)
		ft_putstr_fd("ss\n", 1);
}

void	ft_pa(t_stack **a, t_stack **b, int out)
{
	ft_push(b, a);
	if (out)
		ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_stack **a, t_stack **b, int out)
{
	ft_push(a, b);
	if (out)
		ft_putstr_fd("pb\n", 1);
}
