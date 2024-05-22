/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:14:18 by thda-sil          #+#    #+#             */
/*   Updated: 2024/03/29 21:50:35 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define BLOCK_SIZE 32

enum e_key_codes {
	ESC = 65307,
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	UP = 65362,
	LEFT = 65361,
	DOWN = 65364,
	RIGHT = 65363,
	SPACE = 32
};

enum e_error_codes {
	BER_ERROR = -1,
	MAP_DIMENSION_ERROR = -2,
	PLAYER_ERROR = -3,
	EXIT_ERROR = -4,
	COLLECTABLE_ERROR = -5,
	MAP_ERROR = -6,
	MAP_WALL_ERROR = -7,
	MAP_CHAR_ERROR = -8
};

#endif
