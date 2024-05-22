/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:45:15 by thda-sil          #+#    #+#             */
/*   Updated: 2023/11/10 16:30:40 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_memcmp("Hello", "Hdllo", 5));//pos
	printf("%i\n", ft_memcmp("Hdllo", "Hello", 5));//neg
	printf("%i\n", ft_memcmp("Hello", "Hello", 5));//0
	return (0);
}*/
