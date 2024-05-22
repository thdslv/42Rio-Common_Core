/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:35:11 by thda-sil          #+#    #+#             */
/*   Updated: 2024/05/03 21:29:56 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	polish_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (NULL == buffer || NULL == clean_node)
		return ;
	last_node = find_last_node_checker(*list);
	i = 0;
	while (last_node->str_buffer[i] && (last_node->str_buffer[i] != '\n'))
		i++;
	j = 0;
	while (last_node->str_buffer[i] && last_node->str_buffer[++i])
		buffer[j++] = last_node->str_buffer[i];
	buffer[j] = '\0';
	clean_node->str_buffer = buffer;
	clean_node->next = NULL;
	dealloc(list, clean_node, buffer);
}

char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (NULL == list)
		return (NULL);
	str_len = len_to_new_line(list);
	next_str = malloc((str_len + 1) * sizeof(char));
	if (NULL == next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	append(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = malloc(sizeof(t_list));
	if (NULL == new_node)
		return ;
	last_node = find_last_node_checker(*list);
	if (NULL == last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buffer = buffer;
	new_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	size_t	chars_read;
	char	*buffer;

	while (!found_new_line(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (NULL == buffer)
			return ;
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (!chars_read)
		{
			free(buffer);
			return ;
		}
		buffer[chars_read] = '\0';
		append(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_line(list);
	polish_list(&list);
	return (next_line);
}
