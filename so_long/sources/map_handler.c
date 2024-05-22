/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:00:54 by thda-sil          #+#    #+#             */
/*   Updated: 2024/03/29 20:59:20 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static int	check_map_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	else if (BONUS_ENABLED && c == 'V')
		return (1);
	return (0);
}

static int	check_map_chars(char *map_str)
{
	int	i;

	i = -1;
	while (map_str[++i])
	{
		if (!check_map_char(map_str[i]) && map_str[i] != '\n')
		{
			map_error(MAP_CHAR_ERROR);
			return (MAP_CHAR_ERROR);
		}
	}
	return (1);
}

static void	get_map_dimensions(char **map_str, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (map_str[++i])
	{
		j = -1;
		while (map_str[i][++j])
		{
			if (map_str[i][j] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
				game->player.amount++;
			}
			else if (map_str[i][j] == 'C')
				game->collectable.amount++;
			else if (map_str[i][j] == 'E')
				game->exit.amount++;
		}
	}
	game->map_width = j * BLOCK_SIZE;
	game->map_height = i * BLOCK_SIZE;
}

static char	*get_map_str(char *map_path)
{
	int		fd;
	char	*lines_read;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines_read = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		lines_read = ft_strjoin_free(lines_read, line, 3);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines_read);
}

int	check_map(char *map_path, t_game *game)
{
	char	*map_str;
	int		error_code;

	if (!(map_path && validate_extension(map_path)))
		return (0);
	map_str = get_map_str(map_path);
	if (!map_str || !*map_str || ft_strlen(map_str) == 0)
	{
		map_error(MAP_ERROR);
		free(map_str);
		return (0);
	}
	game->map = ft_split(map_str, '\n');
	get_map_dimensions(game->map, game);
	error_code = validate_map(map_str, game);
	if ((check_map_chars(map_str) < 0) || (error_code < 0))
	{
		free_game(game, 0);
		free(map_str);
		return (0);
	}
	free(map_str);
	return (1);
}
