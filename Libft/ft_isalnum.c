/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:03:40 by thda-sil          #+#    #+#             */
/*   Updated: 2023/11/10 12:53:08 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	int	x;

	x = 48;
	printf("%d\n", ft_isalnum(x));
	x = 65;
	printf("%d\n", ft_isalnum(x));
	x = 97;
	printf("%d\n", ft_isalnum(x));
	x = 123;
	printf("%d", ft_isalnum(x));
	return(0);
}*/
