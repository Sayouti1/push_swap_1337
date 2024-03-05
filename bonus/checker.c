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
			ft_sa(a);
		else if (ft_strcmp_1(move, "sb\n"))
			ft_sb(b);
		else if (ft_strcmp_1(move, "ss\n"))
			ft_ss(a, b);
		else if (ft_strcmp_1(move, "pa\n"))
			ft_pa(a, b);
		else if (ft_strcmp_1(move, "pb\n"))
			ft_pb(a, b);
		else if (ft_strcmp_1(move, "ra\n"))
			ft_ra(a);
		else if (ft_strcmp_1(move, "rb\n"))
			ft_rb(b);
		else if (ft_strcmp_1(move, "rr\n"))
			ft_rr(a, b);
		else if (ft_strcmp_1(move, "rra\n"))
			ft_rra(a);
		else if (ft_strcmp_1(move, "rrb\n"))
			ft_rrb(b);
		else if (ft_strcmp_1(move, "rrr\n"))
			ft_rrr(a, b);
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
	if (!split_av || !split_av->split)
		return (free_split_av(&split_av), ft_putendl_fd("Error", 2), 0);
	if (ft_check_error_stack(split_av))
		return (free_split_av(&split_av), ft_putendl_fd("Error", 2), 0);
	if (ft_init_stack_stack(&a, &split_av))
		return (free_split_av(&split_av), ft_putendl_fd("Error", 2), 0);
	if (ft_is_duplicated(a))
		return (ft_free_stack_print_error(&a));
	ft_checker(&a, &b);
	return (0);
}