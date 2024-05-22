/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:45:01 by thda-sil          #+#    #+#             */
/*   Updated: 2023/11/13 18:54:47 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = nmemb * size;
	if (nmemb && size && ((i / nmemb) != size))
		return ((char *) NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}

/*#include <stdio.h>

int	main(void)
{
	char	*mystr;
	char	*pcstr;
	int	n;

	n = 5;
	mystr = ft_calloc(n, sizeof(char));
	pcstr = calloc(n, 0);
	while (n--)
	{
		printf("%c %c\n", mystr[n], pcstr[n]);
	}
	free(mystr);
	free(pcstr);
	return (0);
}*/
