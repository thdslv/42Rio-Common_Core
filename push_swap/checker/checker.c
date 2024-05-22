/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:43:33 by thda-sil          #+#    #+#             */
/*   Updated: 2024/05/03 21:27:03 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && *s1)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

static void	ft_error_ps(t_node **a, t_node **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	parse_command(t_node **a, t_node **b, char *command)
{
	if (!ft_strcmp(command, "pa\n"))
		pa(a, b, true);
	else if (!ft_strcmp(command, "pb\n"))
		pb(b, a, true);
	else if (!ft_strcmp(command, "sa\n"))
		sa(a, true);
	else if (!ft_strcmp(command, "sb\n"))
		sb(b, true);
	else if (!ft_strcmp(command, "ss\n"))
		ss(a, b, true);
	else if (!ft_strcmp(command, "ra\n"))
		ra(a, true);
	else if (!ft_strcmp(command, "rb\n"))
		rb(b, true);
	else if (!ft_strcmp(command, "rr\n"))
		rr(a, b, true);
	else if (!ft_strcmp(command, "rra\n"))
		rra(a, true);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(b, true);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(a, b, true);
	else
		ft_error_ps(a, b);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	*next_line;
	int		len;

	a = NULL;
	b = NULL;
	if (1 == argc)
		return (0);
	else if (2 == argc)
		argv = ft_split_ps(argv[1], ' ');
	stack_init(&a, argv + 1, 2 == argc);
	len = stack_len(a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		parse_command(&a, &b, next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (stack_sorted(a) && stack_len(a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(a);
}
