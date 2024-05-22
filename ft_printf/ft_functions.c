/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:34:45 by thda-sil          #+#    #+#             */
/*   Updated: 2023/11/27 23:27:18 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(const char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *s)
{
	int	letters;

	letters = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s)
	{
		write(1, s++, 1);
		letters++;
	}
	return (letters);
}

int	ft_putnbr(int nb)
{
	int	letters;

	letters = 0;
	if (nb == -2147483648)
	{
		letters += write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		letters += ft_putchar('-');
		nb *= -1;
		letters += ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		letters += ft_putnbr(nb / 10);
		letters += ft_putnbr(nb % 10);
	}
	else
		letters += ft_putchar(nb + 48);
	return (letters);
}

int	ft_putnbr_base(long unsigned int nb, unsigned int base, int is_upper)
{
	int		letters;
	char	*base_chars;

	if (is_upper)
		base_chars = "0123456789ABCDEF";
	else
		base_chars = "0123456789abcdef";
	letters = 0;
	if (nb >= base)
	{
		letters += ft_putnbr_base(nb / base, base, is_upper);
		letters += ft_putnbr_base(nb % base, base, is_upper);
	}
	else
		letters += ft_putchar(base_chars[nb]);
	return (letters);
}

int	ft_putptr(long unsigned int ptr)
{
	int	letters;

	if (!ptr)
		return (ft_putstr("(nil)"));
	letters = 0;
	letters += ft_putstr("0x");
	letters += ft_putnbr_base(ptr, 16, 0);
	return (letters);
}
