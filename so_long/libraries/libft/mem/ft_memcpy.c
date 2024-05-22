/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 23:17:28 by thda-sil          #+#    #+#             */
/*   Updated: 2023/11/13 19:10:10 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest2;
	unsigned char	*src2;

	i = 0;
	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (!dest && !src && n > 0)
		return (NULL);
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	destiny[] = "Thalles";
	char	source[] = "da Silva";
	char	destiny2[] = "Thalles";

	printf("Source: %s %p\nDest:%s %p\n\n", source, source, destiny, destiny);
	memcpy(destiny, source, 2);
	printf("Source: %s %p\nDest:%s %p\n\n", source, source, destiny, destiny);

	printf("Source: %s %p\nDest2:%s %p\n\n", source, source, destiny2, destiny2);
	ft_memcpy(destiny2, source, 2);
	printf("Source: %s %p\nDest2:%s %p\n", source, source, destiny2, destiny2);
	return (0);
}*/
