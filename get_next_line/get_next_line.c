/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:56:42 by thda-sil          #+#    #+#             */
/*   Updated: 2024/01/29 20:32:04 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd)
{
	static char	*bytes_read;
	char		*line;
	int			read_return;

	line = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	read_return = 1;
	while (read_return > 0 && !find_current_line(bytes_read))
	{
		read_return = read(fd, line, BUFFER_SIZE);
		if (read_return < 0)
		{
			free(line);
			return (NULL);
		}
		line[read_return] = '\0';
		bytes_read = ft_strjoin(bytes_read, line);
	}
	free(line);
	if (!bytes_read)
		return (NULL);
	line = return_current_line(bytes_read);
	bytes_read = return_after_separator(bytes_read);
	return (line);
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (read_file(fd));
}

/*#include <fcntl.h>
#include <stdio.h>
int	main(int c, char **v)
{
	(void) c;
	//(void) v;
	char	*line;
	int	fd = open(v[1], O_RDONLY);

	//printf("%s", get_next_line(fd));

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}*/
