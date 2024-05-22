/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:17:00 by thda-sil          #+#    #+#             */
/*   Updated: 2023/11/10 16:09:16 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

/*#include <stdio.h>

int	main(void)
{
	int	x;

	x = 65;
	printf("%c\n", ft_toupper(x));
	x = 97;
	printf("%c\n", ft_toupper(x));
	return (0);
}*/
