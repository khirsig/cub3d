/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:57:05 by jhagedor          #+#    #+#             */
/*   Updated: 2021/12/13 09:35:41 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void drawVerLine(int i, int drawStart, int drawEnd, t_vars *vars, int side)
{
	while (drawStart <= drawEnd)
	{
		if (side == 1)
			my_mlx_pixel_put(vars, i, drawStart, 0x00FF0000);
		else
			my_mlx_pixel_put(vars, i, drawStart, 0x00A52A2A);
		drawStart++;
	}
	// mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->mlx_img, 0, 0);
}


void	calculate_dist(t_data *data, t_game *game, t_vars *vars)
{
	int		i;
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

	i = 0;
	while(i < 1000)
	{
		if (i < 5)
		{
			printf("dirX %f, dirY %f.  ", game->dirX, game->dirY);
			printf("planeX %f, planeY %f.  ", game->planeX, game->planeY);
		}
		cameraX = 2 * i / 1000.0 - 1;
		rayDirX = game->dirX + game->planeX * cameraX;
		rayDirY = game->dirY + game->planeY * cameraX;

		if (i < 5)
			printf("rayDirX %f, rayDirY %f.  ", rayDirX, rayDirY);
		mapX = game->x_pos;
		mapY = game->y_pos;

		if (rayDirX == 0)
			deltaDistX = 1e30;
		else
			deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		if (rayDirY == 0)
			deltaDistY = 1e30;
		else
			deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
		if (i < 5)
			printf("deltaDistX %f, deltaDistY %f.  ", deltaDistX, deltaDistY);

		//calculate step and initial sideDist
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (game->x_pos - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - game->x_pos) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (game->y_pos - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - game->y_pos) * deltaDistY;
		}
		//perform DDA
		hit = 0;
		while(hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if(data->maze.map[mapY][mapX] == '1')
				hit = 1;
		}
		//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
		if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(1000 / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + 1000 / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + 1000 / 2;
		if(drawEnd >= 1000)
			drawEnd = 1000 - 1;
		if (i < 5)
			printf("This is the distance: %i (Start: %i, End %i)\n", drawEnd - drawStart, drawStart, drawEnd);
		drawVerLine(i, drawStart, drawEnd, vars, side);
		i++;
	}
}


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
				printf("PPos: %i %i\n", h, w);
				game->x_pos = w + 0.5;
				game->y_pos = h + 0.5;
				if (data->maze.map[h][w] == 'N' || data->maze.map[h][w] == 's')
				{
					game->planeX = 0.66;
					if (data->maze.map[h][w] == 'N')
						game->dirY = 1;
					else
						game->dirY = -1;
				}
				else
				{
					game->planeY = 0.66;
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