/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 07:38:15 by thda-sil          #+#    #+#             */
/*   Updated: 2024/02/21 19:22:38 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	if (size == 0)
		return (ft_strlen(src));
	if (ft_strlen(src) < size)
		ft_memcpy(dst, src, ft_strlen(src) + 1);
	else
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (ft_strlen(src));
}

/*#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	const char	*s = "Joao";
	char	d1[6] = "Maria";
	char	d2[6] = "Maria";

	printf("Source: %s\n", s);
	strlcpy(d1, s, 4);
	printf("Strlcpy:%s\n", d1);
	ft_strlcpy(d2, s, 4);
	printf("ft_strlcpy:%s\n", d2);
	return (0);
}*/
