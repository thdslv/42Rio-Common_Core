/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:22:22 by thda-sil          #+#    #+#             */
/*   Updated: 2023/11/10 14:12:05 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if ((c >= 32) && (c <= 126))
		return (1);
	return (0);
}

/*nclude <stdio.h>

int	main(void)
{
	int	x;

	x = 32;
	printf("%d\n", ft_isprint(x));
	x = 31;
	printf("%d", ft_isprint(x));
	return (0);
}*/
