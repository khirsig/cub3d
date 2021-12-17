/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:20:19 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/17 21:01:03 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int 	*load_texture(t_data *data, char *path)
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
	int i;

	i = 0;
	while (i < data->numEnemies)
	{
		if (data->enemy[i].animstep == 0.0000 && data->enemy[i].status == WALK)
			data->enemy[i].animstep += 0.10;
		else if (data->enemy[i].animstep < 6.0000 && data->enemy[i].animstep > 0.0000 && data->enemy[i].status == WALK)
			data->enemy[i].animstep += 0.10;
		else if (data->enemy[i].status == COMBAT && data->enemy[i].idlestep < 5.0000)
			data->enemy[i].idlestep += 0.10 * data->enemy[i].attack_speed;
		else if (data->enemy[i].status == COMBAT && data->enemy[i].idlestep >= 5.0000)
		{
			if ((int) data->enemy[i].animstep == 10)
				data->player.health -= data->enemy[i].damage;
			if (data->enemy[i].animstep >= 12.0000)
			{
				data->enemy[i].idlestep = 0.0000;
				data->enemy[i].animstep = 7.0000;
			}
			data->enemy[i].animstep += 0.10;
		}
		else
		{
			data->enemy[i].status = IDLE;
			data->enemy[i].animstep = 0.0000;
			data->enemy[i].idlestep = 5.0000;
		}
		i++;
	}
}

int	sprite_init(t_data *data)
{
	data->numEnemies = count_enemies(data);
	data->enemy = malloc(sizeof(t_enemy) * data->numEnemies);
	setup_enemies(data);
	printf("%i\n", data->numEnemies);
	return (0);
}