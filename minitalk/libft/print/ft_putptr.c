/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:12:35 by thda-sil          #+#    #+#             */
/*   Updated: 2024/02/29 20:06:16 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putptr(unsigned long int ptr, t_bool is_upper)
{
	if (!ptr)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_putnbr_base(ptr, 16, is_upper));
}
