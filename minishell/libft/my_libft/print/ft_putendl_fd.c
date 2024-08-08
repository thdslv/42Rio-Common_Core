/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 05:26:45 by thda-sil          #+#    #+#             */
/*   Updated: 2024/02/29 19:58:17 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putendl_fd(const char *s, int fd)
{
	int	i;

	i = 0;
	i += ft_putstr_fd(s, fd);
	i += ft_putstr_fd("\n", fd);
	return (i);
}

/*#include <stdio.h>

int	main(void)
{
	char	*str;

	str = "Hi Moulinette";
	ft_putendl_fd(str, 1);
	return (0);
}*/
