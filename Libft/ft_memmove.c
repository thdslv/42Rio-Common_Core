/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:34:06 by thda-sil          #+#    #+#             */
/*   Updated: 2023/11/13 19:25:14 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (src > dest)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		while (n)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	return (dest);
}

/*#include <string.h>
#include <stdio.h>

int	main(void)
{
	char    src[] = "abacaxi";
      	char    dest[] = "chocolate";
	char	dest2[] = "chocolate";

        printf("String: %s\n\n", src);
	memmove(dest, src, 7);
	printf("Memmove: %s\n\n", dest);
        ft_memmove(dest2, src, 7);
	printf("ft_memmove: %s\n", dest2);
        
	return (0);
}*/
