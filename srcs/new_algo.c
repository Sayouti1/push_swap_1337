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

int *get_sorted_arr(t_stack *a)
{
    int		*sorted_tab;
	t_stack	*tmp;
	int		i;

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

int    get_range(t_stack *a)
{
    int size;

    size = ft_stack_len(a);
    if (ft_stack_len(a) <= 50)
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


void    update_max_rank(t_stack **b, size_t  *max_rank, size_t  *max_index)
{
    t_stack *tmp;
    size_t  length;
    size_t  i;

    tmp = *b;
    length = ft_stack_len(tmp);
    *max_index = tmp->index;
    *max_rank = 0;
    i = 0;
    while (tmp)
    {
       
        printf("\nloop : max_rank[%zu], max_index[%zu]", *max_rank, *max_index);
        if (tmp->index > *max_index)
        {
            *max_index = tmp->index;
            *max_rank = i;
        }
        i++;
        tmp = tmp->next;
        if (i == length)
            break;
    }
    printf("\n_____________________PASSED__________________");
}
void    max_to_top(t_stack **b)
{
    size_t  b_length;
    size_t  max_index;
    size_t  max_rank;

    b_length = ft_stack_len(*b);
    update_max_rank(b, &max_rank, &max_index);
    while ((*b)->index != max_index)
    {
        
        if (max_rank <= (b_length/2))
            ft_rb(b);
        else
            ft_rrb(b);
        printf("\nb_length=[%zu], max_rank=[%zu]", b_length, max_rank);
        update_max_rank(b, &max_rank, &max_index);
    }
}

void    push_back_to_a(t_stack **a, t_stack **b)
{
    while (*b)
    {
        max_to_top(b);
        ft_pa(a, b);
    }
}

void    ft_new_algo(t_stack **a, t_stack **b)
{
    int     range;
    int     *arr;
    int     i;
    int     stack_len;

    stack_len = ft_stack_len(*a);
    range = get_range(*a);
    arr = get_sorted_arr(*a);
    i = 0;
    while (*a)
    {
        if (i <= stack_len - 1 && (*a)->value <= arr[i])
        {
            ft_pb(a, b);
            ft_rb(b);
            ++i;
        }
        else if ((i <= stack_len - 1 && (*a)->value > arr[i]) && (range + i <= stack_len - 1 && (*a)->value <= arr[range + i]))
        {
            ft_pb(a, b);
            if (ft_stack_len(*b) > 1
                && (*b)->value < (*b)->next->value)
                ft_sb(b);
            ++i;
        }
        else 
            ft_ra(a);
    }
    free(arr);
    push_back_to_a(a, b);
}
