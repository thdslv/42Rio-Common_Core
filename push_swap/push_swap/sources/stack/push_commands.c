/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:25:53 by thda-sil          #+#    #+#             */
/*   Updated: 2024/05/01 20:41:15 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_node **dest, t_node **src)
{
	t_node	*node_to_push;

	if (NULL == *src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	node_to_push->previous = NULL;
	if (NULL == *dest)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->previous = node_to_push;
		*dest = node_to_push;
	}
}

void	pa(t_node **a, t_node **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_node **b, t_node **a, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
