/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:34:27 by thda-sil          #+#    #+#             */
/*   Updated: 2024/03/29 22:58:20 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_images(t_game *game)
{
	mlx_destroy_image(game->connection, game->floor_image);
	mlx_destroy_image(game->connection, game->wall_image);
	mlx_destroy_image(game->connection, game->collectable.image);
	mlx_destroy_image(game->connection, game->player.up_view);
	mlx_destroy_image(game->connection, game->player.down_view);
	mlx_destroy_image(game->connection, game->player.left_view);
	mlx_destroy_image(game->connection, game->player.right_view);
	mlx_destroy_image(game->connection, game->enemy.image);
	mlx_destroy_image(game->connection, game->exit.image);
}

static void	free_minilibx(t_game *game)
{
	free_images(game);
	mlx_destroy_window(game->connection, game->window);
	mlx_destroy_display(game->connection);
	free(game->connection);
}

void	free_game(t_game *game, int free_lib)
{
	ft_free_matrix(game->map);
	if (free_lib)
		free_minilibx(game);
}

int	close_hook(t_game *game)
{
	free_game(game, 1);
	exit(0);
}
