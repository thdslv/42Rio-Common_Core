/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:51:04 by thda-sil          #+#    #+#             */
/*   Updated: 2023/11/13 17:49:02 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	if (!s)
		return (NULL);
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	if (len == 0 || start >= ft_strlen(s))
		sub[0] = '\0';
	j = 0;
	i = start;
	while ((i < ft_strlen(s)) && (j < len))
	{
		sub[j] = s[i];
		j++;
		i++;
	}
	sub[j] = '\0';
	return (sub);
}

/*#include <stdio.h>

int	main(void)
{
	char	*original = "Hello, World!";

	//"World"
	char	*result1 = ft_substr(original, 7, 5);
	printf("Teste 1: %s\n", result1);
	free(result1);

	//"Hello, World!"
	char	*result2 = ft_substr(original, 0, 13);
	printf("Teste 2: %s\n", result2);
	free(result2);

	//(índice fora da string)
	char	*result3 = ft_substr(original, 14, 5);
	printf("Teste 3: %s\n", result3);
	free(result3);

	//"World!" (ultrapassando o final da string)
	char	*result4 = ft_substr(original, 7, 20);
	printf("Teste 4: %s\n", result4);
	free(result4);

	//String vazia
	char	*result5 = ft_substr("", 0, 5);
	printf("Teste 5: %s\n", result5);
	free(result5);

	return (0);
}*/
