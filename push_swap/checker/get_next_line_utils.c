/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:42:30 by thda-sil          #+#    #+#             */
/*   Updated: 2024/05/02 14:39:10 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	found_new_line(t_list *list)
{
	int	i;

	if (NULL == list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buffer[i] && i < BUFFER_SIZE)
		{
			if (list->str_buffer[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

t_list	*find_last_node_checker(t_list *list)
{
	if (NULL == list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	len_to_new_line(t_list *list)
{
	int	i;
	int	len;

	if (NULL == list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_buffer[i])
		{
			if (list->str_buffer[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}
	return (len);
}

void	copy_str(t_list *list, char *str)
{
	int	i;
	int	j;

	if (NULL == list)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->str_buffer[i])
		{
			if (list->str_buffer[i])
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list->str_buffer[i++];
		}
		str[j] = '\0';
		list = list->next;
	}
}

void	dealloc(t_list **list, t_list *clean_node, char *buffer)
{
	t_list	*temp;

	if (NULL == *list)
		return ;
	while (*list)
	{
		temp = (*list)->next;
		free((*list)->str_buffer);
		free(*list);
		*list = temp;
	}
	*list = NULL;
	if (clean_node->str_buffer[0])
		*list = clean_node;
	else
	{
		free(buffer);
		free(clean_node);
	}
}
