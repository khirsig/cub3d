/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:06:58 by jhagedor          #+#    #+#             */
/*   Updated: 2021/12/20 17:56:11 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	*load_texture(t_data *data, char *path)
{
	void	*img;
	int		*texture;
	int		*addr;
	int		endian;
	int		bits_per_pixel;
	int		line_length;
	int		img_width;
	int		img_height;
	int		x;
	int		y;

	img = mlx_xpm_file_to_image(data->vars.mlx, path, &img_width, &img_height);
	if (img == NULL)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	addr = (int *)mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian);
	y = 0;
	texture = (int *) malloc(sizeof(int) * (img_height * img_width));
	while (y < img_height)
	{
		x = 0;
		while (x < img_width)
		{
			texture[img_width * y + x] = addr[img_width * y + x];
			x++;
		}
		y++;
	}
	free(img);
	free(addr);
	return (texture);
}

void	init_wall(t_data *data)
{
	data->vars.texture = malloc(sizeof(int *) * 4);
	data->vars.texture[0] = load_texture(data, data->maze.north_texture);
	data->vars.texture[1] = load_texture(data, data->maze.south_texture);
	data->vars.texture[2] = load_texture(data, data->maze.east_texture);
	data->vars.texture[3] = load_texture(data, data->maze.west_texture);
}
