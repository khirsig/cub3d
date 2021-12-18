/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:22:02 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/17 16:04:42 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

typedef struct s_sprite {
		double	x;
		double	y;
		double	invDet;
		double	transformX;
		double	transformY;
		double	distance;
		double	spriteX;
		double	spriteY;
		float	uDiv;
		float	vDiv;
		float	vMove;
		int		order;
		int		ScreenX;
		int		height;
		int		width;
		int		drawStartX;
		int		drawStartY;
		int		drawEndX;
		int		drawEndY;
		int		stripe;
		int		texX;
		int		texY;
}				t_sprite;

#endif