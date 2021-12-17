/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:43:16 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/17 10:26:04 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define LEFT 0
# define UP 1
# define RIGHT 2
# define DOWN 3

typedef struct s_player {
	double	x_pos;
	double	y_pos;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	float	speed;
	int		walk_left;
	int		walk_right;
	int		walk_up;
	int		walk_down;
	int		is_rotating;
	int		rotation_direction;
	int		is_sprinting;
	float	health;
	float	stamina;
}				t_player;
#endif