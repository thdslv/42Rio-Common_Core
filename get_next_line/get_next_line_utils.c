/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:20:03 by thda-sil          #+#    #+#             */
/*   Updated: 2024/02/29 21:01:15 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_current_line(const char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		free(s1);
	}
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	if (!*str)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*return_current_line(char *bytes_read)
{
	char	*line;
	int		size;
	int		check;
	int		i;

	size = 0;
	while (bytes_read[size] && bytes_read[size] != '\n')
		size++;
	check = 0;
	if (bytes_read[size] == '\n')
		check++;
	line = (char *) malloc((size + check + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < size)
	{
		line[i] = bytes_read[i];
		i++;
	}
	if (bytes_read[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*return_after_separator(char *bytes_read)
{
	char	*result;
	int		size;
	int		i;

	size = 0;
	while (bytes_read[size] && bytes_read[size] != '\n')
		size++;
	if (!bytes_read[size])
	{
		free(bytes_read);
		return (NULL);
	}
	size++;
	result = (char *) malloc((ft_strlen(bytes_read) - size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (bytes_read[size + i])
	{
		result[i] = bytes_read[size + i];
		i++;
	}
	result[i] = '\0';
	free(bytes_read);
	return (result);
}
