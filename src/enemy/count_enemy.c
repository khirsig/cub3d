/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:21:13 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/17 21:25:05 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	count_enemies(t_data *data)
{
	int	count;
	int	x;
	int	y;

	y = 0;
	count = 0;
	while (data->maze.map[y] != NULL)
	{
		x = 0;
		while (data->maze.map[y][x] != '\0')
		{
			if (data->maze.map[y][x] == 'R' || data->maze.map[y][x] == 'G')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static void	setup_rat(t_data *data, t_enemy *enemy, int x, int y)
{
	enemy->attack_speed = 1;
	enemy->type = RAT;
	enemy->damage = 1;
	enemy->health = 30;
	enemy->move_speed = 0.0005;
	enemy->min_distance = 10.0000;
	enemy->idlestep = 5;
	enemy->status = IDLE;
	enemy->texHeight = 40;
	enemy->texWidth = 32;
	enemy->sprite.vDiv = 1.5;
	enemy->sprite.uDiv = 1.5;
	enemy->sprite.vMove = 400.0;
	enemy->animstep = 0;
	enemy->sprite.x = x + 0.50;
	enemy->sprite.y = y + 0.50;
	enemy->last_x = x;
	enemy->last_y = y;
	enemy->texture = malloc(sizeof(int *) * 15);
	enemy->texture[0] = load_texture(data, "./resources/enemy/rat00.xpm");
	enemy->texture[1] = load_texture(data, "./resources/enemy/rat01.xpm");
	enemy->texture[2] = load_texture(data, "./resources/enemy/rat02.xpm");
	enemy->texture[3] = load_texture(data, "./resources/enemy/rat03.xpm");
	enemy->texture[4] = load_texture(data, "./resources/enemy/rat04.xpm");
	enemy->texture[5] = load_texture(data, "./resources/enemy/rat05.xpm");
	enemy->texture[6] = load_texture(data, "./resources/enemy/rat05.xpm");
	enemy->texture[7] = load_texture(data, "./resources/enemy/rat00.xpm");
	enemy->texture[8] = load_texture(data, "./resources/enemy/rat09.xpm");
	enemy->texture[9] = load_texture(data, "./resources/enemy/rat10.xpm");
	enemy->texture[10] = load_texture(data, "./resources/enemy/rat11.xpm");
	enemy->texture[11] = load_texture(data, "./resources/enemy/rat10.xpm");
	enemy->texture[12] = load_texture(data, "./resources/enemy/rat09.xpm");
	enemy->texture[13] = load_texture(data, "./resources/enemy/rat00.xpm");
	enemy->texture[14] = load_texture(data, "./resources/enemy/rat00.xpm");
}

static void	setup_goblin(t_data *data, t_enemy *enemy, int x, int y)
{
	enemy->attack_speed = 1;
	enemy->type = GOBLIN;
	enemy->damage = 1.5;
	enemy->health = 50;
	enemy->move_speed = 0.0003;
	enemy->min_distance = 22.0000;
	enemy->status = IDLE;
	enemy->idlestep = 5;
	enemy->texHeight = 95;
	enemy->texWidth = 96;
	enemy->sprite.vDiv = 0.5;
	enemy->sprite.uDiv = 0.5;
	enemy->sprite.vMove = 100.0;
	enemy->animstep = 0;
	enemy->sprite.x = x + 0.50;
	enemy->sprite.y = y + 0.50;
	enemy->last_x = x;
	enemy->last_y = y;
	enemy->texture = malloc(sizeof(int *) * 15);
	enemy->texture[0] = load_texture(data, "./resources/enemy/goblin_00.xpm");
	enemy->texture[1] = load_texture(data, "./resources/enemy/goblin_01.xpm");
	enemy->texture[2] = load_texture(data, "./resources/enemy/goblin_02.xpm");
	enemy->texture[3] = load_texture(data, "./resources/enemy/goblin_03.xpm");
	enemy->texture[4] = load_texture(data, "./resources/enemy/goblin_04.xpm");
	enemy->texture[5] = load_texture(data, "./resources/enemy/goblin_05.xpm");
	enemy->texture[6] = load_texture(data, "./resources/enemy/goblin_05.xpm");
	enemy->texture[7] = load_texture(data, "./resources/enemy/goblin_00.xpm");
	enemy->texture[8] = load_texture(data, "./resources/enemy/goblin_09.xpm");
	enemy->texture[9] = load_texture(data, "./resources/enemy/goblin_10.xpm");
	enemy->texture[10] = load_texture(data,"./resources/enemy/goblin_11.xpm");
	enemy->texture[11] = load_texture(data,"./resources/enemy/goblin_10.xpm");
	enemy->texture[12] = load_texture(data,"./resources/enemy/goblin_09.xpm");
	enemy->texture[13] = load_texture(data,"./resources/enemy/goblin_00.xpm");
	enemy->texture[14] = load_texture(data,"./resources/enemy/goblin_00.xpm");
}

void	setup_enemies(t_data *data)
{
	int	x;
	int y;
	int	numEnemy;

	y = 0;
	numEnemy = 0;
	while (data->maze.map[y] != NULL)
	{
		x = 0;
		while (data->maze.map[y][x] != '\0')
		{
			if (data->maze.map[y][x] == 'R')
			{
				setup_rat(data, &data->enemy[numEnemy], x, y);
				numEnemy++;
			}
			if (data->maze.map[y][x] == 'G')
			{
				setup_goblin(data, &data->enemy[numEnemy], x, y);
				numEnemy++;
			}
			x++;
		}
		y++;
	}
}