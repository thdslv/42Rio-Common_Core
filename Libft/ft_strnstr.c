/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:05:16 by thda-sil          #+#    #+#             */
/*   Updated: 2023/11/13 20:33:25 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	x;

	if ((!big || !little) && !len)
		return (NULL);
	if (!ft_strlen(little) || big == little)
		return ((char *)big);
	i = 0;
	while ((big[i] != '\0') && (i < len))
	{
		x = 0;
		while ((big[i + x] == little[x]) && ((i + x) < len))
		{
			x++;
			if (little[x] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <bsd/string.h>

int	main()
{
	printf("%s\n", ft_strnstr("Cars and cats begin with 'ca'", "ca", 29));
	printf("%s\n", ft_strnstr("Cars and cats begin with 'ca'", "ca", 11));
	printf("%s\n", ft_strnstr("Cars and cats begin with 'ca'", "", 29));
	printf("%s\n", ft_strnstr("Cars and cats begin with 'ca'", "ca", 9));
	printf("%s\n", ft_strnstr("", "", 0));
	printf("%s\n", ft_strnstr("abc", "a", 1));
	printf("%s\n", ft_strnstr("a", "a", 0));
	return (0);
}*/
