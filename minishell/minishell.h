/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:14:34 by thda-sil          #+#    #+#             */
/*   Updated: 2024/08/08 16:45:06 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/my_libft/includes/libft.h"

typedef struct s_node
{
	char	*key;
	char	*value;
	int	token;
	struct s_node	*next;
}	t_node;

typedef struct s_command
{
	char	*input;
	char	**input_matrix;
	char	*prompt;
}	t_command;

#endif
