/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:11:55 by jhagedor          #+#    #+#             */
/*   Updated: 2022/01/03 14:32:53 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
Draw player view.
1) Calculate the ray vector (x and y value) for each vertical line.
2) Prepare for DDA algorithm.
3) Find the wall with DDA algorithm.
4) Calculate distance to wall.
5) Calculate x position of wall.
6) Draw vertical line accordingly.
*/
void	draw_view(t_data *data)
{
	int		i;

	i = 0;
	while (i < 1000)
	{
		calculate_ray_vector(data, i);
		calculate_step_and_sideDist(data);
		perform_DDA(data);
		calc_ray_dist(data);
		calc_x_pos(data);
		draw_ver_line(i, data);
		i++;
	}
}
