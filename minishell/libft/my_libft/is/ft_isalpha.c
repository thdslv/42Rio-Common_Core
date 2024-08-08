/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:48:54 by thda-sil          #+#    #+#             */
/*   Updated: 2023/11/10 12:36:45 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	char	x;

	x = 97;
	printf("%d\n", ft_isalpha(x));
	x = 48;
	printf("%d\n", ft_isalpha(x));
	return (0);
}*/
