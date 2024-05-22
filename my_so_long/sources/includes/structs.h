/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:55:46 by thda-sil          #+#    #+#             */
/*   Updated: 2024/03/30 21:02:15 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_player
{
	void	*up_view;
	void	*left_view;
	void	*right_view;
	void	*down_view;
	int		x;
	int		y;
	int		amount;
	char	direction;
}	t_player;

typedef struct s_block
{
	void	*image;
	int		amount;
	int		available;
}	t_block;

typedef struct s_game
{
	void		*connection;
	void		*window;
	char		**map;
	void		*floor_image;
	void		*wall_image;
	int			map_width;
	int			map_height;
	int			wall_error;
	t_player	player;
	t_block		collectable;
	t_block		exit;
	int			exit_possible;
	t_block		enemy;
	int			move_count;
	char		*moves_text;
}	t_game;
