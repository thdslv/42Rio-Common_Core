/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:54:12 by thda-sil          #+#    #+#             */
/*   Updated: 2023/11/04 18:19:26 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*#include <stdio.h>

void	function(unsigned int x, char *p)
{
	
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (*(s + i) != '\0')
	{
		*(str + i) = f(i, *(s + i));
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

/*int	main()
{//pasqualerossi
	char	str[] = "test";

	ft_strmapi(str, function);
	return (0);
}*/
