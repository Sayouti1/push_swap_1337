/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sayo <aes-sayo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 02:05:03 by aes-sayo          #+#    #+#             */
/*   Updated: 2024/01/24 02:05:17 by aes-sayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_push_node(t_stack **stack_x, t_stack *node)
{
	if (*stack_x == NULL)
		*stack_x = node;
	else
	{
		node->next = *stack_x;
		(*stack_x)->prev = node;
		*stack_x = node;
	}
}

t_stack	*ft_last(t_stack *stack_x)
{
	if (!stack_x)
		return (NULL);
	while (stack_x->next)
		stack_x = stack_x->next;
	return (stack_x);
}

size_t	ft_stack_len(t_stack *stack_x)
{
	size_t	i;

	i = 0;
	while (stack_x)
	{
		printf("\n i = [%zu], value = [%d]", i, stack_x->value);
		++i;
		stack_x = stack_x->next;
	}
	return (i);
}

int	ft_is_sorted(t_stack *stack_x)
{
	int	x;

	if (!stack_x)
		return (0);
	x = stack_x->value;
	stack_x = stack_x->next;
	while (stack_x)
	{
		if (x > stack_x->value)
			return (0);
		x = stack_x->value;
		stack_x = stack_x->next;
	}
	return (1);
}
