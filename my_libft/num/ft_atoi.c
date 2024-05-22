/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:43:05 by thda-sil          #+#    #+#             */
/*   Updated: 2024/02/07 20:09:22 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
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
