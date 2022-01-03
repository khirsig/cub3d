/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:06:58 by jhagedor          #+#    #+#             */
/*   Updated: 2022/01/03 13:21:08 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	*load_image(t_data *data, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->vars.mlx, path,
			&data->maze.texture.img_width, &data->maze.texture.img_height);
	if (img == NULL)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	return (img);
}

int	*load_texture(t_data *data, char *path)
{
	int		x;
	int		y;

	data->maze.texture.img = load_image(data, path);
	data->maze.texture.addr = (int *)mlx_get_data_addr(data->maze.texture.img,
			&data->maze.texture.bits_per_pixel,
			&data->maze.texture.line_length, &data->maze.texture.endian);
	y = 0;
	data->maze.texture.texture = (int *) malloc(sizeof(int)
			* (data->maze.texture.img_height * data->maze.texture.img_width));
	while (y < data->maze.texture.img_height)
	{
		x = 0;
		while (x < data->maze.texture.img_width)
		{
			data->maze.texture.texture[data->maze.texture.img_width * y + x]
				= data->maze.texture.addr[data->maze.texture.img_width * y + x];
			x++;
		}
		y++;
	}
	free(data->maze.texture.img);
	free(data->maze.texture.addr);
	return (data->maze.texture.texture);
}

void	init_wall(t_data *data)
{
	data->vars.texture = malloc(sizeof(int *) * 4);
	data->vars.texture[0] = load_texture(data, data->maze.north_texture);
	data->vars.texture[1] = load_texture(data, data->maze.south_texture);
	data->vars.texture[2] = load_texture(data, data->maze.east_texture);
	data->vars.texture[3] = load_texture(data, data->maze.west_texture);
}
