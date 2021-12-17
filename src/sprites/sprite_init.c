/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:20:19 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/17 16:40:43 by khirsig          ###   ########.fr       */
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
	if (img == NULL)
		printf("Error\n");
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

void	cycle_animstep(t_data *data)
{
	if (data->enemy.animstep < 7)
		data->enemy.animstep += 0.10;
	else
		data->enemy.animstep = 0;
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
	data->enemy.animstep = 0;
	data->enemy.texture = malloc(sizeof(int *) * 15);
	data->enemy.texture[0] = load_texture(data, "./resources/enemy/rat00.xpm");
	data->enemy.texture[1] = load_texture(data, "./resources/enemy/rat01.xpm");
	data->enemy.texture[2] = load_texture(data, "./resources/enemy/rat02.xpm");
	data->enemy.texture[3] = load_texture(data, "./resources/enemy/rat03.xpm");
	data->enemy.texture[4] = load_texture(data, "./resources/enemy/rat02.xpm");
	data->enemy.texture[5] = load_texture(data, "./resources/enemy/rat01.xpm");
	data->enemy.texture[6] = load_texture(data, "./resources/enemy/rat00.xpm");
	data->enemy.texture[7] = load_texture(data, "./resources/enemy/rat00.xpm");
	data->enemy.texture[8] = load_texture(data, "./resources/enemy/rat08.xpm");
	data->enemy.texture[9] = load_texture(data, "./resources/enemy/rat09.xpm");
	data->enemy.texture[10] = load_texture(data, "./resources/enemy/rat10.xpm");
	data->enemy.texture[11] = load_texture(data, "./resources/enemy/rat11.xpm");
	data->enemy.texture[12] = load_texture(data, "./resources/enemy/ratd00.xpm");
	data->enemy.texture[13] = load_texture(data, "./resources/enemy/ratd01.xpm");
	data->enemy.texture[14] = load_texture(data, "./resources/enemy/ratd02.xpm");
	return (0);
}