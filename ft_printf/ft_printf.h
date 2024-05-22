/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:15:08 by thda-sil          #+#    #+#             */
/*   Updated: 2023/12/02 16:38:05 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(const char c);
int	ft_putstr(const char *c);
int	ft_putnbr(int nb);
int	ft_putnbr_base(long unsigned int nb, unsigned int base, int is_upper);
int	ft_putptr(long unsigned int ptr);
#endif
