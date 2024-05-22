/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_renderization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:55:06 by thda-sil          #+#    #+#             */
/*   Updated: 2024/03/30 01:21:16 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static void	render_map_texts(t_game *game)
{
	char	*str;
	char	*number;

	number = ft_itoa(game->move_count);
	str = ft_strjoin("Moves: ", number);
	mlx_string_put(game->connection, game->window, 18, 18, 0x00FFFFFF, str);
	free(str);
	free(number);
}

static void	render_exit(t_game *game, int x, int y)
{
	put_image(game, game->exit.image, x, y);
}

static void	render_player(t_game *game)
{
	if (game->player.direction == 'U')
		put_image(game, game->player.up_view, game->player.x * BLOCK_SIZE, \
		game->player.y * BLOCK_SIZE);
	else if (game->player.direction == 'D')
		put_image(game, game->player.down_view, game->player.x * BLOCK_SIZE, \
		game->player.y * BLOCK_SIZE);
	else if (game->player.direction == 'L')
		put_image(game, game->player.left_view, game->player.x * BLOCK_SIZE, \
		game->player.y * BLOCK_SIZE);
	else
		put_image(game, game->player.right_view, game->player.x * BLOCK_SIZE, \
			game->player.y * BLOCK_SIZE);
}

static void	loop_wid(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		put_image(game, game->wall_image, x * BLOCK_SIZE, \
		y * BLOCK_SIZE);
	else if (game->map[y][x] == 'C')
		put_image(game, game->collectable.image, x * BLOCK_SIZE, \
		y * BLOCK_SIZE);
	else if (game->map[y][x] == 'P')
		render_player(game);
	else if (game->map[y][x] == 'E')
		render_exit(game, x * BLOCK_SIZE, \
		y * BLOCK_SIZE);
	else if (game->map[y][x] == 'V')
		put_image(game, game->enemy.image, x * BLOCK_SIZE, \
		y * BLOCK_SIZE);
	else
		put_image(game, game->floor_image, x * BLOCK_SIZE, \
		y * BLOCK_SIZE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (game->map[++y])
	{
		while (game->map[y][++x])
			loop_wid(game, x, y);
		x = -1;
	}
	render_map_texts(game);
}
