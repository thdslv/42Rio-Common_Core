/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:07:20 by thda-sil          #+#    #+#             */
/*   Updated: 2024/03/29 21:48:44 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "../../libraries/libft/includes/libft.h"
# include "../../libraries/minilibx-linux/mlx.h"
# include "structs.h"
# include "constants.h"

// MAP PARSER
int		check_map(char *map_path, t_game *game);
void	render_map(t_game *game);

// MAP VALIDATIONS
int		validate_extension(char *map_path);
int		validate_map(char *map, t_game *game);

// UTILS
void	map_error(int error_code);

// IMAGE HANDLER
int		load_images(t_game *game);
void	put_image(t_game *game, void *image, int x, int y);

// HOOKS
void	free_game(t_game *game, int freelib);
int		close_hook(t_game *game);
int		key_hook(int keycode, t_game *game);

// PLAYER MOVEMENT
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	attack_enemy(t_game *game);

#endif
