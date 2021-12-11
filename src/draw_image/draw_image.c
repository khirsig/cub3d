/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:57:05 by jhagedor          #+#    #+#             */
/*   Updated: 2021/12/10 18:00:00 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
Loops through map and fills position, direction and plane.
*/

void	fill_game(t_data *data, t_game *game)
{
	int	w;
	int	h;

	h = 0;
	while(data->maze.map[h])
	{
		w = 0;
		while (data->maze.map[h][w])
		{
			if (data->maze.map[h][w] == 'N' || data->maze.map[h][w] == 'S'
				|| data->maze.map[h][w] == 'W' || data->maze.map[h][w] == 'E')
			{
				game->x_pos = w + 0.5;
				game->y_pos = h + 0.5;
				if (data->maze.map[h][w] == 'N' || data->maze.map[h][w] == 's')
				{
					game->planeY = 0.66;
					if (data->maze.map[h][w] == 'N')
						game->dirY = 1;
					else
						game->dirY = -1;
				}
				else
				{
					game->planeX = 0.66;
					if (data->maze.map[h][w] == 'O')
						game->dirX = 1;
					else
						game->dirX = -1;
				}
			}
			w++;
		}
		h++;
	}
}