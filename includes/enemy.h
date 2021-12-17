/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:22:02 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/17 14:20:57 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

# define RAT 0;
# define SKELETON 1;
# define GOBLIN 2;

# include "sprite.h"

typedef struct s_enemy {
	t_sprite	sprite;
	int			type;
	int			*texture;
	int			texWidth;
	int			texHeight;
	float		health;
	float		damage;
	float		attack_speed;
	float		move_speed;
}				t_enemy;

#endif