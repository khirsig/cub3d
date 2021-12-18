/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:06:58 by jhagedor          #+#    #+#             */
/*   Updated: 2021/12/18 18:10:49 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	load_image(t_data *data, int *texture, char *path)
{
	void	*image;
	int		width;
	int		height;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		x;
	int		y;

	width = 64;
	height = 64;
	bits_per_pixel = 8;
	line_length = 64;
	image = mlx_xpm_file_to_image(data->vars.mlx, path, &width, &height);
	if (image == NULL)
		ft_putstr_fd("Error\n", 2);
	addr = (int *)mlx_get_data_addr(image, &bits_per_pixel, &line_length, &data->vars.endian);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			texture[width * y + x] = addr[width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->vars.mlx, image);
}
void	load_texture(t_data *data)
{
	data->vars.texture = malloc(sizeof(int *) * 4);
	data->vars.texture[0] = malloc(64 * 64 * sizeof(int));
	data->vars.texture[1] = malloc(64 * 64 * sizeof(int));
	data->vars.texture[2] = malloc(64 * 64 * sizeof(int));
	data->vars.texture[3] = malloc(64 * 64 * sizeof(int));
	load_image(data, data->vars.texture[0], data->maze.north_texture);
	load_image(data, data->vars.texture[1], data->maze.south_texture);
	load_image(data, data->vars.texture[2], data->maze.east_texture);
	load_image(data, data->vars.texture[3], data->maze.west_texture);
}