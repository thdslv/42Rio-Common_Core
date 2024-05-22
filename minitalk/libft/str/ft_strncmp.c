/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:20:24 by thda-sil          #+#    #+#             */
/*   Updated: 2023/11/13 19:58:10 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((s1[i] > s2[i]) || (s1[i] < s2[i]))
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_strncmp("Hello", "Hdllo", 5));//pos
	printf("%i\n", ft_strncmp("Hdllo", "Hello", 5));//neg
	printf("%i\n", ft_strncmp("Hello", "Hello", 5));//0
	return (0);
}*/
