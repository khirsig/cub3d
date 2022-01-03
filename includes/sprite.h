/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:22:02 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/03 14:39:39 by jhagedor         ###   ########.fr       */
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