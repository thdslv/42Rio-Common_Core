/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:27:31 by thda-sil          #+#    #+#             */
/*   Updated: 2024/02/07 20:10:37 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnbr(int nb)
{
	int	digits;

	digits = 0;
	if (nb == -2147483648)
		digits += write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		digits += ft_putchar('-');
		nb *= -1;
		digits += ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		digits += ft_putnbr(nb / 10);
		digits += ft_putnbr(nb % 10);
	}
	else
		digits += ft_putchar(nb + 48);
	return (digits);
}
