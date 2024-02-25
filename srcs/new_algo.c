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
#include <stdio.h>

// int get_val_at_index(t_stack *a, int i)
// {
//     while (a)
//     {
//         if (a->index == i)
//             return (a->value);
//         a = a->next;
//     }
// }

int *get_sorted_arr(t_stack **a)
{
    int		*sorted_tab;
	t_stack	*tmp;
	int		i;

	i = 0;
	sorted_tab = (int *)malloc(sizeof(int) * ft_stack_len(*a));
	if (!sorted_tab)
		return (NULL);
	tmp = *a;
	while (tmp)
	{
		sorted_tab[i++] = tmp->value;
		tmp = tmp->next;
	}
	ft_selection_sort(sorted_tab, ft_stack_len(*a));
	ft_set_indexes(a, sorted_tab, ft_stack_len(*a));
    return (sorted_tab);
}

// void    update_vars(t_vars *vars)
// {
//     vars->start -= vars->offset;
//     if (vars->start < 0)
//         vars->start = 0;
//     vars->end += vars->offset;
//     if (vars->end >= vars->size)
//         vars->end = vars->size - 1;
// }

// void    ft_new_algo(t_stack **a, t_stack **b)
// {
//     int     *arr;
//     t_vars  vars;

//     arr = get_sorted_arr(a);
//     vars.size = ft_stack_len(*a);
//     vars.mid = vars.size / 2 - 1;
//     vars.offset = vars.size / arr[vars.mid];
//     update_vars(&vars);

//     while (!ft_is_sorted(*a) || ft_stack_len(*a) != vars.size)
//     {
//         if ((*a)->index >= vars.start && (*a)->index <= vars.end)
//         {
//             ft_pb(a, b);
//             if ((*b)->value <= arr[vars.mid])
//                 ft_rb(b);
//         }
//     }

// }

void    init_range(t_stack *a, t_vars *vars)
{
    vars->size = ft_stack_len(a);
    if (ft_stack_len(a) <= 100)
        vars->range = 14; 
        // vars->range = 13; 624
        // vars->range = 11; 627
        // vars->range = 10; 645
        // vars->range = 9; 644
        // vars->range = 8; 665
        // vars->range = 7; 684
    else 
    if (ft_stack_len(a) <= 200)
        vars->range = 17;
    else 
    if (ft_stack_len(a) <= 500)
        vars->range = 28;
        // vars->range = 27; 5136
        // vars->range = 28; 5149
        // vars->range = 29; 5158
        // vars->range = 30; 5154
        // vars->range = 34; 5159
        // vars->range = 36; 5180
        // vars->range = 38; 5194
        //vars->range = 30;
    else
        vars->range = 50;
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
    // printf("\nmax returned = [%d]", max);
	return (max);
}

void    max_to_top(t_stack **b, int size)
{
    int    i;

    i = ft_get_index(*b, ft_get_max(*b));
    while (i != 0)
    {
        if (i <= size / 2)
            ft_rb(b);
        else 
            ft_rrb(b);
        i = ft_get_index(*b, ft_get_max(*b));
    }
}

void    push_back_to_a(t_stack **a, t_stack **b)
{
    while (*b)
    {
        // printf("\n[%d] a.lengt = [%d], b.length = [%d]", (*b)->value, ft_stack_len(*a), ft_stack_len(*b));
        max_to_top(b, ft_stack_len(*b));
        // if (ft_stack_len(*b) <= 25)
        //     puts("below 25");
        ft_pa(a, b);
        // if (ft_stack_len(*b) <= 25)
        //     puts("below 25 aaa");
    }
}

void    ft_new_algo(t_stack **a, t_stack **b)
{
    t_vars vars;
    int     *arr;
    int     i;

    init_range(*a, &vars);
    arr = get_sorted_arr(a);
    i = 0;
    while (*a)
    {
        if ((*a)->value <= arr[i])
        {
            ft_pb(a, b);
            ft_rb(b);
            ++i;
        }
        else if ((*a)->value > arr[i] && (*a)->value <= arr[vars.range + i])
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


/*

int    get_max_rank(t_node **stack)
{
    int        max_rank;
    t_node    *current_node;

    current_node = *stack;
    max_rank = INT_MIN;
    while (current_node)
    {
        if (current_node->rank > max_rank)
            max_rank = current_node->rank;
        current_node = current_node->next;
    }
    return (max_rank);
}

int    get_max_rank_index(t_node **stack)
{
    int        max_rank;
    t_node    *current_node;
    int        index;

    max_rank = get_max_rank(stack);
    index = 0;
    current_node = *stack;
    while (current_node)
    {
        if (current_node->rank == max_rank)
            return (index);
        current_node = current_node->next;
        index++;
    }
    return (-1);
}

void    ft_get_big(t_node **stack_B, int size)
{
    int    i;

    while (1)
    {
        i = get_max_rank_index(stack_B);
        if (i == 0)
            break ;
        else if (i <= size / 2)
            rb(stack_B, 1);
        else if (i > size / 2)
            rrb(stack_B, 1);
    }
}

void    push_to_b(t_node **stack_a, t_node **stack_b, int *arr, int range)
{
    int    i;

    i = 0;
    while (*stack_a)
    {
        if ((*stack_a)->value <= arr[i])
        {
            pb(stack_a, stack_b);
            rb(stack_b, 1);
            i++;
        }
        else if ((*stack_a)->value > arr[i]
            && (*stack_a)->value <= arr[range + i])
        {
            pb(stack_a, stack_b);
            if (ft_lstsize(*stack_b) > 1
                && (*stack_b)->value < (*stack_b)->next->value)
                sb(stack_b, 1);
            i++;
        }
        else
            ra(stack_a, 1);
    }
}

void    push_back_to_a(t_node **stack_b, t_node **stack_a)
{
    while (*stack_b)
    {
        ft_get_big(stack_b, ft_lstsize(*stack_b));
        pa(stack_b, stack_a);
    }
}


*/
