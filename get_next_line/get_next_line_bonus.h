/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:56:56 by thda-sil          #+#    #+#             */
/*   Updated: 2024/02/29 21:07:16 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 42
# endif

char	*get_next_line(int fd);
char	*read_file(int fd);
int		find_current_line(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*return_current_line(char *bytes_read);
char	*return_after_separator(char *bytes_read);
#endif
