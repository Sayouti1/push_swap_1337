#include "push_swap.h"

int	ft_strcmp_1(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_checker(t_stack **a, t_stack **b)
{
    size_t  a_length;
	char	*move;

    a_length = ft_stack_len(*a);    
	move = get_next_line(0);
	while (move)
    {
		if (ft_strcmp_1(move, "sa\n"))
			ft_sa(a, 0);
		else if (ft_strcmp_1(move, "sb\n"))
			ft_sb(b, 0);
		else if (ft_strcmp_1(move, "ss\n"))
			ft_ss(a, b, 0);
		else if (ft_strcmp_1(move, "pa\n"))
			ft_pa(a, b, 0);
		else if (ft_strcmp_1(move, "pb\n"))
			ft_pb(a, b, 0);
		else if (ft_strcmp_1(move, "ra\n"))
			ft_ra(a, 0);
		else if (ft_strcmp_1(move, "rb\n"))
			ft_rb(b, 0);
		else if (ft_strcmp_1(move, "rr\n"))
			ft_rr(a, b, 0);
		else if (ft_strcmp_1(move, "rra\n"))
			ft_rra(a, 0);
		else if (ft_strcmp_1(move, "rrb\n"))
			ft_rrb(b, 0);
		else if (ft_strcmp_1(move, "rrr\n"))
			ft_rrr(a, b, 0);
		else
		{
			ft_putstr_fd("Error\n", 2);
			free(move);
			free_stack(a);
			return ;
		}
		free(move);
		move = get_next_line(0);
    }
	if (ft_is_sorted(*a) && !ft_stack_len(*b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
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
	ft_checker(&a, &b);
	return (0);
}
