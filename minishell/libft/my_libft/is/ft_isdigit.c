/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:00:13 by thda-sil          #+#    #+#             */
/*   Updated: 2023/11/10 12:41:17 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	int	x;

	x = 48;
	printf("%d\n", ft_isdigit(x));
	x = 97;
	printf("%d", ft_isdigit(x));
	return (0);
}*/
