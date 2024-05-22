/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:45:35 by thda-sil          #+#    #+#             */
/*   Updated: 2024/02/29 22:31:31 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if ((!dst || !src) && !size)
		return (0);
	i = 0;
	j = 0;
	len = ft_strlen(src) + ft_strlen(dst);
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	while (dst[j])
		j++;
	while (src[i] && (j < (size - 1)))
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (len);
}

/*#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	size_t	n = 2;
	char	dest1[6] = "Tes";
	char	src[] = "te";

	printf("Meu retorno: %zu\n", ft_strlcat(dest1, src, strlen(dest1) + 1 + n));
	printf("ft_strlcat: %s\n\n", dest1);
	char	dest2[6] = "Tes";
	printf("Retorno original: %zu\n", strlcat(dest2, src, strlen(dest2) + 1 + n));
	printf("Dest original: %s\n\n", dest2);
	return (0);
}*/
