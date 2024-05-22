/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:52:58 by thda-sil          #+#    #+#             */
/*   Updated: 2024/02/29 23:15:42 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_nbrlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nbrlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[len] = '\0';
	while (n > 0)
	{
		str[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}

/*#include <stdio.h>

int	main()
{
	printf("%s\n", ft_itoa(1));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(0));
	printf("%d", ft_nbrlen(50));
	return (0);
}*/
