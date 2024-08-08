/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:53:10 by thda-sil          #+#    #+#             */
/*   Updated: 2024/02/29 20:05:19 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnbr_base(long long int nbr, unsigned int base, int is_upper)
{
	int		digits;
	char	*base_chars;

	if (is_upper)
		base_chars = "0123456789ABCDEF";
	else
		base_chars = "0123456789abcdef";
	digits = 0;
	if (nbr < 0)
	{
		digits += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= base)
	{
		digits += ft_putnbr_base(nbr / base, base, is_upper);
		digits += ft_putnbr_base(nbr % base, base, is_upper);
	}
	else
		digits += ft_putchar(base_chars[nbr]);
	return (digits);
}
