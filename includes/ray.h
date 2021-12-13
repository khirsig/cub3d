/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:20:11 by jhagedor          #+#    #+#             */
/*   Updated: 2021/12/13 15:32:19 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

typedef struct s_ray {
	double	cameraX;
	//ray direction
	double	rayDirX;
	double	rayDirY;
	//which box of the map we're in
	int		mapX;
	int		mapY;
	//length of ray from current position to next x or y-side
	double	sideDistX;
	double	sideDistY;
	//length of ray from one x or y-side to next x or y-side
	double	deltaDistX;
	double	deltaDistY;
	//direction to step in x or y-direction (either +1 or -1)
	int		stepX;
	int		stepY;
	//was there a wall hit?
	int		hit;
	//was a NS or a EW wall hit?
	int		side;
	double	perpWallDist;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
}				t_ray;
#endif