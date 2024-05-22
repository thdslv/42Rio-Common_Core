/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:01:51 by thda-sil          #+#    #+#             */
/*   Updated: 2024/03/29 21:39:39 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	move_up(t_game *game)
{
	game->player.direction = 'U';
	if (game->map[game->player.y - 1][game->player.x] != '1')
	{
		if (game->map[game->player.y - 1][game->player.x] == 'E'
				&& game->collectable.amount != 0)
			return ;
		game->map[game->player.y][game->player.x] = '0';
		game->player.y -= 1;
		if (game->map[game->player.y][game->player.x] == 'C')
			game->collectable.amount--;
		else if ((game->map[game->player.y][game->player.x] == 'E'
			&& game->collectable.amount == 0) ||
				game->map[game->player.y][game->player.x] == 'V')
			close_hook(game);
		game->map[game->player.y][game->player.x] = 'P';
		game->move_count++;
		ft_printf("Move count: %d\r", game->move_count);
		render_map(game);
	}
}

void	move_down(t_game *game)
{
	game->player.direction = 'D';
	if (game->map[game->player.y + 1][game->player.x] != '1')
	{
		if (game->map[game->player.y + 1][game->player.x] == 'E'
				&& game->collectable.amount != 0)
			return ;
		game->map[game->player.y][game->player.x] = '0';
		game->player.y += 1;
		if (game->map[game->player.y][game->player.x] == 'C')
			game->collectable.amount--;
		else if ((game->map[game->player.y][game->player.x] == 'E'
			&& game->collectable.amount == 0) ||
				game->map[game->player.y][game->player.x] == 'V')
			close_hook(game);
		game->map[game->player.y][game->player.x] = 'P';
		game->move_count++;
		ft_printf("Move count: %d\r", game->move_count);
		render_map(game);
	}
}

void	move_left(t_game *game)
{
	game->player.direction = 'L';
	if (game->map[game->player.y][game->player.x - 1] != '1')
	{
		if (game->map[game->player.y][game->player.x - 1] == 'E'
				&& game->collectable.amount != 0)
			return ;
		game->map[game->player.y][game->player.x] = '0';
		game->player.x -= 1;
		if (game->map[game->player.y][game->player.x] == 'C')
			game->collectable.amount--;
		else if ((game->map[game->player.y][game->player.x] == 'E'
			&& game->collectable.amount == 0) ||
				game->map[game->player.y][game->player.x] == 'V')
			close_hook(game);
		game->map[game->player.y][game->player.x] = 'P';
		game->move_count++;
		ft_printf("Move count: %d\r", game->move_count);
		render_map(game);
	}
}

void	move_right(t_game *game)
{
	game->player.direction = 'R';
	if (game->map[game->player.y][game->player.x + 1] != '1')
	{
		if (game->map[game->player.y][game->player.x + 1] == 'E'
				&& game->collectable.amount != 0)
			return ;
		game->map[game->player.y][game->player.x] = '0';
		game->player.x += 1;
		if (game->map[game->player.y][game->player.x] == 'C')
			game->collectable.amount--;
		else if ((game->map[game->player.y][game->player.x] == 'E'
			&& game->collectable.amount == '0') ||
				game->map[game->player.y][game->player.x] == 'V')
			close_hook(game);
		game->map[game->player.y][game->player.x] = 'P';
		game->move_count++;
		ft_printf("Move count: %d\r", game->move_count);
		render_map(game);
	}
}

void	attack_enemy(t_game *game)
{
	if (game->map[game->player.y - 1][game->player.x] == 'V')
		game->map[game->player.y - 1][game->player.x] = '0';
	else if (game->map[game->player.y + 1][game->player.x] == 'V')
		game->map[game->player.y + 1][game->player.x] = '0';
	else if (game->map[game->player.y][game->player.x - 1] == 'V')
		game->map[game->player.y][game->player.x - 1] = '0';
	else if (game->map[game->player.y][game->player.x + 1] == 'V')
		game->map[game->player.y][game->player.x + 1] = '0';
	render_map(game);
}
