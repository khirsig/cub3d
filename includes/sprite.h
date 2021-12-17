/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:22:02 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/17 11:30:48 by khirsig          ###   ########.fr       */
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
		int		ScreenX;
		int		height;
		int		width;
		int		drawStartX;
		int		drawStartY;
		int		drawEndX;
		int		drawEndY;
		int		stripe;
		int		texX;
}				t_sprite;

#endif