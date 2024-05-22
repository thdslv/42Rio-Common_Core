/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:13:24 by thda-sil          #+#    #+#             */
/*   Updated: 2024/05/02 12:45:27 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	int					value;
	int					current_position;
	int					push_price;
	bool				above_middle;
	bool				cheapest;
	struct s_node		*target_node;
	struct s_node		*previous;
	struct s_node		*next;
}		t_node;

// Handle input
char	**ft_split_ps(char *str, char separator);

// Create stack
void	stack_init(t_node **a, char **argv, bool flag_argc_2);
void	init_nodes(t_node *a, t_node *b);
void	set_current_position(t_node *stack);
void	set_price(t_node *a, t_node *b);
void	set_cheapest(t_node *b);

// Handle errors - Free
int		syntax_error(char *str_nbr);
void	error_free(t_node **a, char **argv, bool flag_argc_2);
void	free_stack(t_node **stack);
void	free_matrix(char **argv);
int		repetition_error(t_node *a, int nbr);

// Linked list utils
void	append_node(t_node **stack, int nbr);
t_node	*find_last_node(t_node *head);
bool	stack_sorted(t_node *stack);
int		stack_len(t_node *stack);
t_node	*find_smallest(t_node *stack);
t_node	*return_cheapest(t_node *stack);
void	finish_rotation(t_node **stack, t_node *top_node, char stack_name);

//          Commands

// swap
void	sa(t_node **a, bool checker);
void	sb(t_node **b, bool checker);
void	ss(t_node **a, t_node **b, bool checker);
// rotate
void	ra(t_node **a, bool checker);
void	rb(t_node **b, bool checker);
void	rr(t_node **a, t_node **b, bool checker);
// reverse rotate
void	rra(t_node **a, bool checker);
void	rrb(t_node **b, bool checker);
void	rrr(t_node **a, t_node **b, bool checker);
// push
void	pa(t_node **a, t_node **b, bool checker);
void	pb(t_node **b, t_node **a, bool checker);

// Algorithms
void	sort_3(t_node **a);
void	push_swap(t_node **a, t_node **b);
void	sort_5(t_node **a, t_node **b);

#endif
