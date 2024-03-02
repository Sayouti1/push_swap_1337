#include "push_swap.h"

void	ft_checker(t_stack **a, t_stack **b)
{
    size_t  a_length;
	char	*move;

    a_length = ft_stack_len(*a);    
	while (!ft_is_sorted(*a) || ft_stack_len(*a) != a_length)
    {
		move = get_next_line(0);
		if (!ft_strncmp(move, "pa\n", 4))
			ft_pa(a, b ,0);
		else if (!ft_strncmp(move, "pb\n", 4))
				ft_pb(a, b ,0);
		else if (!ft_strncmp(move, "ra\n", 4))
				ft_ra(a, b ,0);
		else if (!ft_strncmp(move, "rb\n", 4))
				ft_rb(a, b ,0);
		else if (!ft_strncmp(move, "rr\n", 4))
				ft_rr(a, b ,0);
		else if (!ft_strncmp(move, "sa\n", 4))
				ft_sa(a, 0);
		else if (!ft_strncmp(move, "sb\n", 4))
				ft_sb(b, 0);
		else if (!ft_strncmp(move, "ss\n", 4))
				ft_ss(a, b, 0);
		else if (!ft_strncmp(move, "rra\n", 5))
				ft_rra(a, 0);
		else if (!ft_strncmp(move, "rrb\n", 5))
				ft_rrb(b, 0);
		else if (!ft_strncmp(move, "rrr\n", 5))
				ft_rrr(a, b, 0);
		else
		{
			ft_putstr_fd("Error\n", 1);
			free(move);
			free_stack(a);
			return ;
		}
		free(move);
    }
	if (ft_is_sorted(*a) && !ft_stack_len(*b))
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("OK", 1);
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
