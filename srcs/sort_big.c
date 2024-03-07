/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sayo <aes-sayo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:58:05 by aes-sayo          #+#    #+#             */
/*   Updated: 2024/03/05 16:58:07 by aes-sayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_max_rank(t_stack **b, size_t *max_rank, size_t *max_index)
{
	t_stack	*tmp;
	size_t	i;

	tmp = *b;
	*max_index = tmp->index;
	*max_rank = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->index > *max_index)
		{
			*max_index = tmp->index;
			*max_rank = i;
		}
		i++;
		tmp = tmp->next;
	}
}

void	max_to_top(t_stack **b)
{
	size_t	b_length;
	size_t	max_index;
	size_t	max_rank;

	b_length = ft_stack_len(*b);
	update_max_rank(b, &max_rank, &max_index);
	while ((*b)->index != max_index)
	{
		if (max_rank <= (b_length / 2))
			ft_rb(b);
		else
			ft_rrb(b);
		update_max_rank(b, &max_rank, &max_index);
	}
}

void	push_back_to_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		max_to_top(b);
		ft_pa(a, b);
	}
}

int	*init_vars_get_arr(t_stack *a, int *range, size_t *stack_len, size_t *i)
{
	*stack_len = ft_stack_len(a);
	*range = get_range(a);
	*i = 0;
	return (get_sorted_arr(a));
}

void printf_stack(t_stack **a)
{
	t_stack *tmp;

	system("clear");
	tmp = *a;
	while (tmp)
	{
		printf ("\n %d", tmp->value);
		tmp = tmp->next;
	}
	
}

int	ft_is_rev_sorted(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	size_t	i;

	i = 0;
	tmp2 = *a;
	while (tmp2)
	{
		tmp = tmp2->next;
		if (tmp && tmp2->value < tmp->value)
			i = 0;
		++i;
		tmp2 = tmp2->next;
	}
	if (i < ft_stack_len(*a) / 2)
		return (0);
	return (1);
}


int	ft_sort_reversed(t_stack **a, t_stack **b , size_t length)
{
	(void)length;
	while (*a)
	{
		ft_pb(a, b);
	}
	// if (ft_stack_len(*a) > 1 && (*a)->value > (*a)->next->value)
	// 	ft_sa(a);
	// while (length-- > 2)
	// 	ft_pa(a, b);
	return (1);
}

int	get_max_value(t_stack **a)
{
	int	max;
	t_stack	*tmp;

	tmp = *a;
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

void	ft_sort_big(t_stack **a, t_stack **b, size_t *stack_len)
{
	int		range;
	int		*arr;
	size_t	i;

	arr = init_vars_get_arr(*a, &range, stack_len, &i);
	while (*a)
	{
		if (get_max_value(a) == (*a)->value && ft_is_rev_sorted(a)
			&&  ft_stack_len(*a) > 10 && ft_sort_reversed(a, b, ft_stack_len(*a)))
			break ;
		if (i <= *stack_len - 1 && (((*a)->value <= arr[i]) || ((range + i
						<= *stack_len - 1 && (*a)->value <= arr[range + i]))))
		{
			ft_pb(a, b);
			if ((*b)->value <= arr[i])
				ft_rb(b);
			else if (ft_stack_len(*b) > 1 && (*b)->value < (*b)->next->value)
				ft_sb(b);
			i++;
		}
		else
			ft_ra(a);
	}
	free(arr);
	push_back_to_a(a, b);
	// printf_stack(a);
	// printf("\na_length[%zu]", ft_stack_len(*a));
}
