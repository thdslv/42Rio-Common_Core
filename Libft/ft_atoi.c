/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:43:05 by thda-sil          #+#    #+#             */
/*   Updated: 2023/11/13 18:41:44 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	return (res * sign);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("%i\n", ft_atoi("  \n -123a1"));
	printf("%i\n", atoi("  \n -123a1"));
	printf("%i\n", ft_atoi("\t \n \t +-123a1"));
	printf("%i\n", atoi("\t \n \t +-123a1"));
	return (0);
}*/
