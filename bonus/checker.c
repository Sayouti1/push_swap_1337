#include "push_swap.h"


int check_nl(char *str)
{
    int i;

    if (!str || !str[0])
        return (0);
    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (1);
        ++i;
    }
    return (0);
}
int	ft_strlen_gnl(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *old_line, char *buff)
{
	int		i;
	int		j;
	char	*new_line;

	j = ft_strlen_gnl(buff) + ft_strlen_gnl(old_line);
	new_line = (char *)malloc(sizeof(char) * (j + 1));
	if (!new_line)
	{
		free(old_line);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (old_line && old_line[i])
		new_line[j++] = old_line[i++];
	i = 0;
	while (buff[i])
		new_line[j++] = buff[i++];
	new_line[j] = '\0';
	if (old_line)
		free(old_line);
	return (new_line);
}


char    *read_command()
{
    int     byte_read;
    char    *read;
    char    *buff;

    buff = (char*)malloc(sizeof(char) * 4);
    if (!buff)
        return (NULL);
    buff[0] = 0;
    byte_read = 1;
    read = NULL;
    while (!check_nl(buff) && byte_read > 0)
    {
        byte_read = read(1, buff, 4);
        if (byte_read < 0)
            puts("ERROR");
        buff[byte_read] = '\0';
        read = ft_strjoin_gnl(read, buff);
    }
    free(buff);
    return (read);
}
void	ft_checker(t_stack **a, t_stack **b)
{
    size_t  a_length;

    a_length = ft_stack_len(*a);
    
	while (!ft_is_sorted(*a) || ft_stack_len(*a) != a_length)
    {
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
	ft_checker(&a, &b);
	return (0);
}
