/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 05:05:33 by thda-sil          #+#    #+#             */
/*   Updated: 2024/02/29 20:07:48 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_putstr_fd(const char *s, int fd)
{
	size_t	i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		ft_putchar_fd(s[i], fd);
	return (i);
}

/*#include <stdio.h>

int	main(void)
{
	char	str[] = "Quarante-deux";

	ft_putstr_fd(str, 1);
	return (0);
}*/
