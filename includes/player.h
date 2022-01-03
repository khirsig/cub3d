/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:43:16 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/03 14:43:01 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define LEFT 0
# define UP 1
# define RIGHT 2
# define DOWN 3

# include "weapon.h"

typedef struct s_player {
	t_weapon	weapon;
	double		x_pos;
	double		y_pos;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	float		speed;
	int			walk_left;
	int			walk_right;
	int			walk_up;
	int			walk_down;
	int			is_rotating;
	int			rotation_direction;
	int			is_sprinting;
	float		health;
	float		stamina;
	float		damage;
}				t_player;
#endif