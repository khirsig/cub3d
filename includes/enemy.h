/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:22:02 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/15 21:39:11 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

# define RAT 0
# define SKELETON 1
# define GOBLIN 2

# define IDLE 0
# define WALK 1
# define COMBAT 2
# define DEAD 3

# include "sprite.h"

typedef struct s_enemy {
	t_sprite	sprite;
	int			**texture;
	int			type;
	int			tex_width;
	int			tex_height;
	int			status;
	int			last_x;
	int			last_y;
	float		health;
	float		damage;
	float		attack_speed;
	float		move_speed;
	float		animstep;
	float		idlestep;
	float		min_distance;
}				t_enemy;

#endif