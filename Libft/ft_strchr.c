/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:26:50 by thda-sil          #+#    #+#             */
/*   Updated: 2023/11/10 16:15:38 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	char	str[] = "Thalles";
	int		x;

	x = 97;
	printf("%s", ft_strchr(str, x));
	return (0);
}*/
