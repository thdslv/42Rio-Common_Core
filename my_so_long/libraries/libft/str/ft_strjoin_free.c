/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 23:06:41 by thda-sil          #+#    #+#             */
/*   Updated: 2024/02/29 23:24:17 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int free_str)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (free_str == 1 || free_str == 3)
		free(s1);
	if (free_str == 2 || free_str == 3)
		free(s2);
	return (str);
}
