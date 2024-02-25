/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subject_methods_gen.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sayo <aes-sayo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 02:12:16 by aes-sayo          #+#    #+#             */
/*   Updated: 2024/01/24 02:12:27 by aes-sayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_top(t_stack *stack_x)
{
	if (!stack_x)
		return (NULL);
	return (stack_x);
}

void	ft_swap(t_stack **stack_a)
{
	t_stack	*a;
	t_stack	*b;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	a = *stack_a;
	b = (*stack_a)->next;
	a->next = b->next;
	a->prev = b;
	b->next = a;
	b->prev = NULL;
	*stack_a = b;
}

void	ft_push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (!*from)
		return ;
	tmp = *from;
	(*from) = tmp->next;
	if (*from)
		(*from)->prev = NULL;
	if (*to)
	{
		tmp->next = *to;
		(*to)->prev = tmp;
	}
	else
		tmp->next = NULL;
	*to = tmp;
}

void	ft_rotate(t_stack **stack_x)
{
	t_stack	*a;
	t_stack	*last;

	if (*stack_x == NULL || (*stack_x)->next == NULL)
		return ;
	a = *stack_x;
	last = ft_last(*stack_x);
	a->prev = last;
	last->next = a;
	*stack_x = a->next;
	(*stack_x)->prev = NULL;
	a->next = NULL;
}

void	ft_reverse_rotate(t_stack **stack_x)
{
	t_stack	*last;

	if (*stack_x == NULL || (*stack_x)->next == NULL)
		return ;
	last = ft_last(*stack_x);
	last->prev->next = NULL;
	(*stack_x)->prev = last;
	last->next = (*stack_x);
	last->prev = NULL;
	(*stack_x) = last;
}