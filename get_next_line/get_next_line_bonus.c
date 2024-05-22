/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:56:35 by thda-sil          #+#    #+#             */
/*   Updated: 2024/02/29 21:02:13 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(int fd)
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
		bytes_read[fd] = ft_strjoin(bytes_read[fd], line);
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
#include <stdio.h>
int     main(int c, char **v)
{
        (void) c;
        char    *line;
        int     fd = open(v[1], O_RDONLY);

        //printf("%s", get_next_line(fd));

        while ((line = get_next_line(fd)))
        {
                printf("%s", line);
                free(line);
        }
        return (0);
}*/
