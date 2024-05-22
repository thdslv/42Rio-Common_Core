/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:05:33 by thda-sil          #+#    #+#             */
/*   Updated: 2024/03/29 21:10:48 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	validate_extension(char *map_path)
{
	if (ft_strnstr(map_path + ft_strlen(map_path) - 4, ".ber", 4))
		return (1);
	map_error(BER_ERROR);
	return (0);
}

static int	validate_map_entities(t_game *game)
{
	if (game->map_width == game->map_height)
		return (MAP_DIMENSION_ERROR);
	else if (game->wall_error)
		return (MAP_WALL_ERROR);
	else if (game->player.amount != 1)
		return (PLAYER_ERROR);
	else if (game->exit.amount != 1)
		return (EXIT_ERROR);
	else if (game->exit.available != game->exit.amount)
		return (EXIT_ERROR);
	else if (game->collectable.amount == 0)
		return (COLLECTABLE_ERROR);
	else if (game->collectable.available != game->collectable.amount)
		return (COLLECTABLE_ERROR);
	return (1);
}

static void	validate_player_path(t_game *game, char **map, int x, int y)
{
	if (game->wall_error)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'E')
		return ;
	if (map[y][x] == 'C')
		game->collectable.available++;
	if (map[y][x + 1] == 'E' || map[y][x - 1] == 'E' ||
			map[y + 1][x] == 'E' || map[y - 1][x] == 'E')
		game->exit.available = 1;
	map[y][x] = '1';
	if (map[y][x + 1] != '1')
		validate_player_path(game, map, x + 1, y);
	if (map[y][x - 1] != '1')
		validate_player_path(game, map, x - 1, y);
	if (map[y + 1][x] != '1')
		validate_player_path(game, map, x, y + 1);
	if (map[y - 1][x] != '1')
		validate_player_path(game, map, x, y - 1);
}

static void	validate_map_walls(char **map_str, int *wall_error)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map_str[i])
	{
		j = 0;
		while (map_str[i][j])
		{
			if ((i == 0) || (i == ft_matrix_len(map_str) - 1))
			{
				if (map_str[i][j] != '1')
					*wall_error = 1;
			}
			else if ((j == 0) || (j == (ft_strlen(map_str[i]) - 1)))
			{
				if (map_str[i][j] != '1')
					*wall_error = 1;
			}
			j++;
		}
		i++;
	}
}

int	validate_map(char *map_str, t_game *game)
{
	char	**map_matrix;
	int		error_code;

	map_matrix = ft_split(map_str, '\n');
	if (!map_matrix)
		return (0);
	validate_map_walls(map_matrix, &game->wall_error);
	validate_player_path(game, map_matrix, game->player.x, game->player.y);
	ft_free_matrix(map_matrix);
	error_code = validate_map_entities(game);
	if (error_code < 0)
		map_error(error_code);
	return (error_code);
}
