/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:31:18 by thda-sil          #+#    #+#             */
/*   Updated: 2023/11/13 20:13:20 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

/*#include <stdio.h>

int	main(void)
{
	char 	str[] = "Thalles da Silva";
	int	a;

	a = 65;
	printf("Original: %s\n", str);
	ft_memset(str, a, 7);
	printf("Modified: %s\n", str);
	return (0);
}*/
