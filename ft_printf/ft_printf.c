/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:07:03 by thda-sil          #+#    #+#             */
/*   Updated: 2023/12/06 16:09:26 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		letters += ft_putptr(va_arg(args, long unsigned int));
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

	letters = 0;
	va_start(args, format);
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

/*#include <stdio.h>
int	main(void)
{
	char	*str = "teste: %% %c %s %i %d %x %X %u %p\n\n";

	ft_printf("%d", ft_printf(str, 'c', "aaa", 42, 84, 42, 42, 42, &str));
	printf("\n\n");
	ft_printf("%d", printf(str, 'c', "aaa", 42, 84, 42, 42, 42,  &str));
	printf("\n\n\n\n\n");
	return (0);
}*/
