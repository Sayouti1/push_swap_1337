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

t_argv	*ft_new_argv(char *av)
{
	t_argv	*argv;

	argv = (t_argv *)malloc(sizeof(t_argv));
	if (!argv)
		return (NULL);
	argv->split = ft_split(av, ' ');
	argv->next = NULL;
	return (argv);
}
void	ft_argv_add(t_argv	**head, t_argv *av)
{
	t_argv	*tmp;

	if (!*head)
	{
		*head = av;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = av;
}
int	check_overflow(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i] == '0')
		++i;
	if (ft_strlen(str) - i > 10)
		return (1);
	return (0);
}
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_argv	*split_av;
	int		i;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	i = 1;
	split_av = ft_new_argv(av[i++]);
	while (i < ac)
		ft_argv_add(&split_av, ft_new_argv(av[i++]));
	if (!split_av)
		return (ft_putendl_fd("Error", 2), 0);
	if (ft_check_error_stack(split_av))
		return (ft_putendl_fd("Error", 2), 0);
	if (ft_init_stack_stack(&a, &split_av))
		return (ft_putendl_fd("Error", 2), 0);
	if (ft_is_duplicated(a))
		return (ft_free_stack_print_error(&a));
	ft_sort_algo(&a, &b);
	return (0);
}









/*
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
*/