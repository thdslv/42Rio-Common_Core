/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:01:28 by thda-sil          #+#    #+#             */
/*   Updated: 2024/05/01 21:43:30 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

void	finish_rotation(t_node **stack, t_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_middle)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_middle)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	move_nodes(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_middle
		&& cheapest_node->target_node->above_middle)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_middle)
		&& !(cheapest_node->target_node->above_middle))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b, false);
}

void	push_swap(t_node **a, t_node **b)
{
	t_node	*smallest;
	int		len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		sort_5(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a, false);
	}
	sort_3(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_middle)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
