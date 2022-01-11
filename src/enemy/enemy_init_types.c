/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_init_types.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 09:14:20 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/10 15:52:24 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	setup_rat_load_textures(t_data *data, t_enemy *enemy)
{
	enemy->texture = malloc(sizeof(int *) * 19);
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
	enemy->texture[15] = load_texture(data, "./resources/enemy/ratd00.xpm");
	enemy->texture[16] = load_texture(data, "./resources/enemy/ratd01.xpm");
	enemy->texture[17] = load_texture(data, "./resources/enemy/ratd02.xpm");
	enemy->texture[18] = load_texture(data, "./resources/enemy/ratd02.xpm");
}

void	setup_rat(t_data *data, t_enemy *enemy, int x, int y)
{
	enemy->attack_speed = 1.5;
	enemy->type = RAT;
	enemy->damage = 1;
	enemy->health = 30;
	enemy->move_speed = 0.00025;
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
	setup_rat_load_textures(data, enemy);
}

static void	setup_goblin_load_texture(t_data *data, t_enemy *enemy)
{
	enemy->texture = malloc(sizeof(int *) * 19);
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
	enemy->texture[10] = load_texture(data, "./resources/enemy/goblin_11.xpm");
	enemy->texture[11] = load_texture(data, "./resources/enemy/goblin_10.xpm");
	enemy->texture[12] = load_texture(data, "./resources/enemy/goblin_09.xpm");
	enemy->texture[13] = load_texture(data, "./resources/enemy/goblin_00.xpm");
	enemy->texture[14] = load_texture(data, "./resources/enemy/goblin_00.xpm");
	enemy->texture[15] = load_texture(data, "./resources/enemy/goblind_00.xpm");
	enemy->texture[16] = load_texture(data, "./resources/enemy/goblind_01.xpm");
	enemy->texture[17] = load_texture(data, "./resources/enemy/goblind_02.xpm");
	enemy->texture[18] = load_texture(data, "./resources/enemy/goblind_02.xpm");
}

void	setup_goblin(t_data *data, t_enemy *enemy, int x, int y)
{
	enemy->attack_speed = 1;
	enemy->type = GOBLIN;
	enemy->damage = 1.5;
	enemy->health = 50;
	enemy->move_speed = 0.00020;
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
	setup_goblin_load_texture(data, enemy);
}
