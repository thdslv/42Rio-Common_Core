/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:51:07 by thda-sil          #+#    #+#             */
/*   Updated: 2024/03/30 06:44:28 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game = (t_game){0};
	if (argc != 2)
		ft_printf("Usage: ./so_long MAP_PATH.ber\n");
	else
	{
		if (!check_map(argv[1], &game))
			return (0);
		game.connection = mlx_init();
		load_images(&game);
		game.window = mlx_new_window(game.connection, game.map_width,
				game.map_height, "so_long");
		render_map(&game);
		mlx_key_hook(game.window, key_hook, &game);
		mlx_hook(game.window, 17, 0, close_hook, &game);
		mlx_loop(game.connection);
	}
}
