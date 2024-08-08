/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:09:30 by thda-sil          #+#    #+#             */
/*   Updated: 2023/11/10 13:06:08 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	int	x;

	x = 0;
	printf("%d\n", ft_isascii(x));
	x = 127;
	printf("%d\n", ft_isascii(x));
	x = 128;
	printf("%d", ft_isascii(x));
	return (0);
}*/
