/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:11:32 by thda-sil          #+#    #+#             */
/*   Updated: 2024/05/01 21:24:21 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	stack_sorted(t_node *stack)
{
	if (NULL == stack)
		return (0);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_node	*find_highest(t_node *stack)
{
	int		highest;
	t_node	*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	sort_3(t_node **a)
{
	t_node	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a, false);
	else if ((*a)->next == highest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	sort_5(t_node **a, t_node **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}
