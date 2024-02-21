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

void	ft_sorted_stack(t_stack **a)
{
	int		*sorted_tab;
	t_stack	*tmp;
	int		i;

	i = 0;
	sorted_tab = (int *)malloc(sizeof(int) * ft_stack_len(*a));
	if (!sorted_tab)
		return ;
	tmp = *a;
	while (tmp)
	{
		sorted_tab[i++] = tmp->value;
		tmp = tmp->next;
	}
	ft_selection_sort(sorted_tab, ft_stack_len(*a));
	ft_set_indexes(a, sorted_tab, ft_stack_len(*a));
	free(sorted_tab);
}

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

	if (ft_is_sorted(*a))
		return ;
	while (ft_stack_len(*a) > 3)
	{
		tmp = *a;
		while (tmp && tmp->value != ft_get_min(*a))
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

void	ft_sort_large_stack(t_stack **a, t_stack **b)
{
	int	stack_a_length;
	int	i;
	int	j;

	ft_sorted_stack(a);
	stack_a_length = ft_stack_len(*a);
	i = 0;
	while (!ft_is_sorted(*a))
	{
		j = 0;
		while (j < stack_a_length)
		{
			if (((ft_top(*a)->index >> i) & 1) == 1)
				ft_ra(a);
			else
				ft_pb(a, b);
			++j;
		}
		while (*b)
			ft_pa(a, b);
		++i;
	}
}
