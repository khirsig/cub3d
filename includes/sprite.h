/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:22:02 by khirsig           #+#    #+#             */
/*   Updated: 2022/02/15 21:59:35 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

typedef struct s_sprite {
	double	x;
	double	y;
	double	inv_det;
	double	transform_x;
	double	transform_y;
	double	distance;
	double	sprite_x;
	double	sprite_y;
	float	u_div;
	float	v_div;
	float	v_move;
	int		order;
	int		screen_x;
	int		height;
	int		width;
	int		draw_start_x;
	int		draw_start_y;
	int		draw_end_x;
	int		draw_end_y;
	int		stripe;
	int		tex_x;
	int		tex_y;
}				t_sprite;

#endif