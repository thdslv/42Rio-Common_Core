/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:56:35 by thda-sil          #+#    #+#             */
/*   Updated: 2024/03/13 18:01:07 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	find_current_line(const char *str)
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

static char	*return_current_line(const char *bytes_read)
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

static char	*return_after_separator(char *bytes_read)
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

static char	*read_file(int fd)
{
	static char	*bytes_read[MAX_FD] = {NULL};
	char		*line;
	int			read_return;

	line = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	read_return = 1;
	while (read_return > 0 && !find_current_line(bytes_read[fd]))
	{
		read_return = read(fd, line, BUFFER_SIZE);
		if (read_return < 0)
		{
			free(line);
			return (NULL);
		}
		line[read_return] = '\0';
		bytes_read[fd] = ft_strjoin_gnl(bytes_read[fd], line);
	}
	free(line);
	if (!bytes_read[fd])
		return (NULL);
	line = return_current_line(bytes_read[fd]);
	bytes_read[fd] = return_after_separator(bytes_read[fd]);
	return (line);
}

char	*get_next_line(int fd)
{
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	return (read_file(fd));
}

/*#include <fcntl.h>

int     main(int c, char **v)
{
    int             fd;
    char  *line;
    (void) c;

    fd = open(v[1], O_RDONLY);
    //printf("%s", get_next_line(fd));
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    return (0);
}*/