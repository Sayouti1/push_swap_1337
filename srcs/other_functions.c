/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sayo <aes-sayo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 02:18:12 by aes-sayo          #+#    #+#             */
/*   Updated: 2024/01/24 02:18:23 by aes-sayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}

int	ft_get_index(t_stack *a, int value)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->value == value)
			return (i);
		++i;
		a = a->next;
	}
	return (-1);
}

int	ft_check_error(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]) && (str[i][j] != '-'
					&& str[i][j] != '+'))
				return (1);
			if (str[i][j] && (str[i][j] == '-' || str[i][j] == '+'))
				if (!str[i][j + 1] || (str[i][j + 1] && !ft_isdigit(str[i][j
							+ 1])))
					return (1);
			++j;
		}
		++i;
	}
	return (0);
}

int	ft_init_stack(t_stack **a, char **tab, int from_argv)
{
	int	i;

	i = 0;
	while (tab[i])
		++i;
	--i;
	while (i >= 0)
	{
		if (ft_atol(tab[i]) > INT_MAX || ft_atol(tab[i]) < INT_MIN)
		{
			free_stack(a);
			return (1);
		}
		ft_push_node(a, ft_new_node(ft_atol(tab[i])));
		--i;
	}
	if (!from_argv)
	{
		i = 0;
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
	return (0);
}

int	ft_is_duplicated(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}
