/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sayo <aes-sayo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 02:52:43 by aes-sayo          #+#    #+#             */
/*   Updated: 2024/01/24 02:52:46 by aes-sayo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_algo(t_stack **a, t_stack **b)
{
	if (!ft_is_sorted(*a))
	{
		if (ft_stack_len(*a) <= 10)
			ft_sort_min(a, b);
		else
			ft_new_algo(a, b);
	}
	free_stack(a);
}

int	ft_free_stack_print_error(t_stack **a)
{
	free_stack(a);
	ft_putendl_fd("Error", 2);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_av;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		split_av = ft_split(av[1], ' ');
		if (!split_av || ft_check_error(split_av) || ft_init_stack(&a, split_av,
				0))
		{
			if (split_av)
			{
				int i = 0;
				while (split_av[i])
				{
					free(split_av[i++]);
				}
				free(split_av);
				ft_putendl_fd("Error", 2);
			}
			return (0);
		}
	}
	else if (ft_check_error(av + 1) || ft_init_stack(&a, av + 1, 1))
		return (ft_free_stack_print_error(&a));
	if (ft_is_duplicated(a))
		return (ft_free_stack_print_error(&a));
	ft_sort_algo(&a, &b);
	return (0);
}
