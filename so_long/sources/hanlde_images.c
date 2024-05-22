/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hanlde_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:09:33 by thda-sil          #+#    #+#             */
/*   Updated: 2024/03/29 21:46:59 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include <stdio.h>

void	put_image(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->connection, game->window, image,
		x, y);
	mlx_do_sync(game->connection);
}

static void	load_image(t_game *game, void **image, char *path)
{
	int	width;
	int	height;

	if (image)
		*image = mlx_xpm_file_to_image(game->connection, path, &width, &height);
}

int	load_images(t_game *game)
{
	load_image(game, &game->floor_image, "sources/textures/map/floor.xpm");
	load_image(game, &game->wall_image, "sources/textures/map/wall.xpm");
	load_image(game, &game->exit.image, "sources/textures/map/exit.xpm");
	load_image(game, &game->collectable.image,
		"sources/textures/collectable/collectable.xpm");
	load_image(game, &game->enemy.image, "sources/textures/enemy/enemy.xpm");
	load_image(game, &game->player.up_view,
		"sources/textures/player/player_up.xpm");
	load_image(game, &game->player.down_view,
		"sources/textures/player/player_down.xpm");
	load_image(game, &game->player.left_view,
		"sources/textures/player/player_left.xpm");
	load_image(game, &game->player.right_view,
		"sources/textures/player/player_right.xpm");
	return (1);
}
