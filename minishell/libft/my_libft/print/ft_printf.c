/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:29:48 by thda-sil          #+#    #+#             */
/*   Updated: 2024/02/29 20:11:45 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_arg_format(const char c, va_list args)
{
	int	letters;

	letters = 0;
	if (c == '%')
		letters += ft_putchar('%');
	else if (c == 'c')
		letters += ft_putchar(va_arg(args, int));
	else if (c == 's')
		letters += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		letters += ft_putptr(va_arg(args, unsigned long int), 0);
	else if (c == 'd' || c == 'i')
		letters += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		letters += ft_putnbr_base(va_arg(args, unsigned int), 10, 0);
	else if (c == 'x')
		letters += ft_putnbr_base(va_arg(args, unsigned int), 16, 0);
	else if (c == 'X')
		letters += ft_putnbr_base(va_arg(args, unsigned int), 16, 1);
	return (letters);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		letters;

	va_start(args, format);
	letters = 0;
	while (*format)
	{
		if (*format == '%')
			letters += ft_arg_format(*(++format), args);
		else
			letters += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (letters);
}
