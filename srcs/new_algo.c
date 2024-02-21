/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sayo <aes-sayo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:18:48 by aes-sayo          #+#    #+#             */
/*   Updated: 2024/02/21 17:18:51 by aes-sayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_val_at_index(t_stack *a, int i)
{
    while (a)
    {
        if (a->index == i)
            return (a->value);
        a = a->next;
    }
}

void    ft_new_algo(t_stack **a, t_stack **b)
{
    int mid;
    int offset;
    int start;
    int end;

    mid = ft_stack_len(*a) / 2 - 1;
    offset =  ft_stack_len(*a) / get_val_at_index(*a, mid);
    start = mid - offset;
    end = mid + offset;
    
    ft_sorted_stack(a);


}
