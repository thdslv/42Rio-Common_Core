/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:20:11 by thda-sil          #+#    #+#             */
/*   Updated: 2023/11/10 16:11:41 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

/*#include <stdio.h>

int	main(void)
{
	int	x;

	x = 97;
	printf("%c\n", ft_tolower(x));
	x = 65;
	printf("%c\n", ft_tolower(x));
	return (0);
}*/
