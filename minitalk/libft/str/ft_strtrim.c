/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:53:11 by thda-sil          #+#    #+#             */
/*   Updated: 2023/11/10 20:30:37 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_check_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	while (s1)
	{
		if (ft_check_set(((char)*s1), set) == 1)
			s1++;
		else
			break ;
	}
	size = ft_strlen(s1);
	while (size != 0)
	{
		if (ft_check_set(s1[size - 1], set) == 1)
			size--;
		else
			break ;
	}
	trimmed = (char *)malloc((size + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, (char *)s1, size + 1);
	return (trimmed);
}

/*#include <stdio.h>

int	main(void)
{
	char	str[] = "*Biquini*de*bolinha*amarelinha*";

	printf("%s\n", str);
	printf("%s", ft_strtrim(str, "*"));
	return (0);	
}*/
