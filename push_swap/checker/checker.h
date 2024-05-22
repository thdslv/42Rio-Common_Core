/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:28:58 by thda-sil          #+#    #+#             */
/*   Updated: 2024/05/02 14:39:53 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define BUFFER_SIZE 4
# include <fcntl.h>
# include "../push_swap/includes/push_swap.h"

typedef struct s_list
{
	char			*str_buffer;
	struct s_list	*next;
}	t_list;

// get_next_line and utils
char	*get_next_line(int fd);// 1
void	create_list(t_list **list, int fd);// 2
int		found_new_line(t_list *list);// 3
void	append(t_list **list, char *buffer);// 4
t_list	*find_last_node_checker(t_list *list);// 5
char	*get_line(t_list *list);// 6
int		len_to_new_line(t_list *list);// 6
void	copy_str(t_list *list, char *str);// 7
void	polish_list(t_list **list);// 8
void	dealloc(t_list **list, t_list *clean_node, char *buffer);// 9
#endif
