/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:20:19 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/17 16:10:13 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int 	*load_texture(t_data *data, char *path)
{
	void *img;
	int *texture;
	int *addr;
	int endian;
	int bits_per_pixel;
	int line_length;
	int	img_width;
	int img_height;
	int x;
	int y;

	img = mlx_xpm_file_to_image(data->vars.mlx, path, &img_width, &img_height);
	// img_height = 40;
	// img_width = 32;
	if (img == NULL)
		printf("Error\n");
	printf("Test\n");
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
	return (texture);
}

int	sprite_init(t_data *data)
{

	data->numEnemies = 1;
	data->enemy.sprite.y = 2.5;
	data->enemy.sprite.x = 2.5;
	data->enemy.texHeight = 40;
	data->enemy.texWidth = 32;
	data->enemy.sprite.uDiv = 1.5;
	data->enemy.sprite.vDiv = 1.5;
	data->enemy.sprite.vMove = 400.0;
	data->enemy.texture = load_texture(data, "./resources/enemy/rat00.xpm");
	return (0);
}