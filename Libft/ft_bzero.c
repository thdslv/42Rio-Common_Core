/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:38:12 by thda-sil          #+#    #+#             */
/*   Updated: 2023/11/13 18:53:00 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*#include <stdio.h>

int     main(void)
{
        char    str[] = "Thalles da Silva";
        int     a;

        a = 65;
        printf("%s\t%p\n", str, str);

        ft_bzero(str, 7);

        printf("%s\t\t\t%p\n", str, str);
        return (0);
}*/
