/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sayo <aes-sayo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 01:56:21 by aes-sayo          #+#    #+#             */
/*   Updated: 2024/01/24 01:56:40 by aes-sayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_selection_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			++j;
		}
		++i;
	}
}

void	ft_sort_three(t_stack **a)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	while (!ft_is_sorted(*a))
	{
		tmp = *a;
		if (tmp->value > tmp->next->value)
		{
			if (tmp->next->next && tmp->value > tmp->next->next->value)
				ft_ra(a);
			else
				ft_sa(a);
		}
		else if (tmp->value > tmp->next->next->value)
			ft_rra(a);
		else if (tmp->next->value > tmp->next->next->value)
			ft_rra(a);
	}
	free_stack(a);
}

void	ft_sort_min(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	while (ft_stack_len(*a) > 3)
	{
		tmp = *a;
		while (tmp->value != ft_get_min(*a))
		{
			if (ft_get_index(*a, ft_get_min(*a)) <= (ft_stack_len(*a) / 2))
				ft_ra(a);
			else
				ft_rra(a);
			tmp = *a;
		}
		ft_pb(a, b);
	}
	ft_sort_three(a);
	while (*b)
		ft_pa(a, b);
}

