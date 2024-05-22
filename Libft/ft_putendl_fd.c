/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 05:26:45 by thda-sil          #+#    #+#             */
/*   Updated: 2023/11/10 16:41:48 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putstr_fd("\n", fd);
}

/*#include <stdio.h>

int	main(void)
{
	char	*str;

	str = "Hi Moulinette";
	ft_putendl_fd(str, 1);
	return (0);
}*/
