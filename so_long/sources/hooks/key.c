/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:16:03 by thda-sil          #+#    #+#             */
/*   Updated: 2024/03/29 22:59:34 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_hook(game);
	else if (keycode == W || keycode == UP)
		move_up(game);
	else if (keycode == A || keycode == LEFT)
		move_left(game);
	else if (keycode == S || keycode == DOWN)
		move_down(game);
	else if (keycode == D || keycode == RIGHT)
		move_right(game);
	else if (keycode == SPACE)
		attack_enemy(game);
	else
		ft_printf("\nInvalid key\n");
	return (0);
}
