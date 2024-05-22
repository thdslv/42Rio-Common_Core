/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:31:07 by thda-sil          #+#    #+#             */
/*   Updated: 2024/04/21 18:39:20 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static long	ft_atol(const char *str)
{
	long	num;
	int		is_negative;
	int		i;

	i = 0;
	while (str[i] && ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' '))
		i++;
	is_negative = 1;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		is_negative *= -1;
		i++;
	}
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * is_negative);
}

void	stack_init(t_node **a, char **argv, bool flag_argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			error_free(a, argv, flag_argc_2);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, flag_argc_2);
		if (repetition_error(*a, (int)nbr))
			error_free(a, argv, flag_argc_2);
		append_node(a, (int)nbr);
		i++;
	}
	if (flag_argc_2)
		free_matrix(argv);
}
