/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:54:15 by thda-sil          #+#    #+#             */
/*   Updated: 2024/03/29 23:01:38 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	error(void)
{
	ft_putendl_fd("Error", 2);
}

void	map_error(int error_code)
{
	error();
	if (error_code == BER_ERROR)
		ft_putendl_fd("The map file has to be .ber", 2);
	else if (error_code == MAP_DIMENSION_ERROR)
		ft_putendl_fd("The map has to be rectangular", 2);
	else if (error_code == PLAYER_ERROR)
		ft_putendl_fd("The map needs one and only one player", 2);
	else if (error_code == EXIT_ERROR)
		ft_putendl_fd("The map needs only and only one exit", 2);
	else if (error_code == COLLECTABLE_ERROR)
		ft_putendl_fd("The map needs at least one collectable", 2);
	else if (error_code == MAP_ERROR)
		ft_putendl_fd("The map wasn't properly built", 2);
	else if (error_code == MAP_WALL_ERROR)
		ft_putendl_fd("The map has to be enclosed by walls", 2);
	else if (error_code == MAP_CHAR_ERROR)
		ft_putendl_fd("The map can only have P,C,E,0,1 and V (as bonus)", 2);
}
