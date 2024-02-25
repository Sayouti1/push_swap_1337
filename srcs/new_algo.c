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
    if (ft_stack_len(a) <= 100)
        return (14); 
        // vars->range = 13; 624
        // vars->range = 11; 627
        // vars->range = 10; 645
        // vars->range = 9; 644
        // vars->range = 8; 665
        // vars->range = 7; 684
    else if (ft_stack_len(a) <= 200)
        return (17);
    else if (ft_stack_len(a) <= 500)
        return (28);
        // vars->range = 27; 5136
        // vars->range = 28; 5149
        // vars->range = 29; 5158
        // vars->range = 30; 5154
        // vars->range = 34; 5159
        // vars->range = 36; 5180
        // vars->range = 38; 5194
        //vars->range = 30;
    else
        return (50);
}


int	ft_get_max(t_stack *a)
{
	int	max;

	max = a->value;
    a = a->next;
	while (a)
	{
		if (a->value > max)
			max = a->value;
		a = a->next;
	}
	return (max);
}

void    max_to_top(t_stack **b, int size)
{
    int    i;

    i = ft_get_index(*b, ft_get_max(*b));
    if (i == -1)
    {
        puts("ERRROOR");
        getchar();
    }
    while (i != 0)
    {
        if (i <= size / 2)
            ft_rb(b);
        else 
            ft_rrb(b);
        i = ft_get_index(*b, ft_get_max(*b));
        if (i == -1)
        {
            puts("ERRROOR");
            getchar();
        }
        
        //printf("\n size = [%d] i = [%d] b->value = [%d]", size, i,(*b)->value);
    }
    printf("\n b->value = [%d]", (*b)->value);
}

void    push_back_to_a(t_stack **a, t_stack **b)
{
    while (*b)
    {
        max_to_top(b, ft_stack_len(*b));
        
        ft_pa(a, b);
        printf("\n a->value = [%d]", (*a)->value);
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
