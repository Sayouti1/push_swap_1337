/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sayo <aes-sayo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:12:19 by aes-sayo          #+#    #+#             */
/*   Updated: 2024/03/06 00:12:21 by aes-sayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_sorted_arr(t_stack *a)
{
	int			*sorted_tab;
	t_stack		*tmp;
	size_t		i;

	i = 0;
	sorted_tab = (int *)malloc(sizeof(int) * ft_stack_len(a));
	if (!sorted_tab)
		return (NULL);
	tmp = a;
	while (tmp)
	{
		sorted_tab[i++] = tmp->value;
		tmp = tmp->next;
	}
	ft_selection_sort(sorted_tab, ft_stack_len(a));
	ft_set_indexes(a, sorted_tab, ft_stack_len(a));
	return (sorted_tab);
}

int	get_range(t_stack *a)
{
	int	size;

	size = ft_stack_len(a);
	if (ft_stack_len(a) <= 25)
		return (7);
	else if (ft_stack_len(a) <= 50)
		return (13);
	else if (ft_stack_len(a) <= 100)
		return (14);
	else if (ft_stack_len(a) <= 200)
		return (17);
	else if (ft_stack_len(a) <= 550)
		return (28);
	else
		return (50);
}
/*
	9
	0
	5
	12
	3
	6
	7
	8
	1
	4
	2
	10
*/