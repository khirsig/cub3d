/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 09:58:00 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/20 17:02:38 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
** -----------------------------------------------------------------------------
** Includes
*/
# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"
# include <stdio.h>
# include <math.h>
# include "maze.h"
# include "player.h"
# include "vars.h"
# include "ray.h"
# include "enemy.h"
/*
** -----------------------------------------------------------------------------
** Structs and typedef.
*/
typedef struct s_data {
	t_maze		maze;
	t_player	player;
	t_enemy		*enemy;
	t_vars		vars;
	t_ray		ray;
	int			file;
	int			x_length;
	int			y_length;
	int			read_length;
	int			numEnemies;
	int			mouse_variant;
	int			mouse_rotation;
	int			mouse_width;
	int			mouse_height;
	int			*mouse_on_enemy;
	int			mouse_x;
	int			mouse_y;
	int			**mouse_texture;
}				t_data;

/*
** -----------------------------------------------------------------------------
** Function prototypes
*/

/*
** Initializer
*/
void	initializer(t_data *data);
void	init_player(t_data *data);
void	fill_player(t_data *data);
void	init_wall(t_data *data);
void	init_enemy(t_data *data);
void	init_interface(t_data *data);
/*
** Parser
*/
void	parser(t_data *data, char *file);
void	parser_color_wall(t_data *data);
void	parser_color(char *str, int i, t_data *data);
void	parser_map(t_data *data, char *file);
int		parser_map_x_length(t_data *data, char *file);
int		parser_map_y_length(t_data *data, char *file);
int		parser_map_error(t_data *data, char **map);

/*
** Minimap
*/
int		minimap(t_data *data);
/*
** Loop
*/
int		gameloop(t_data *data);
int		player_move(int keystroke, t_data *data);
int		display_vitals(t_data *data);
/*
** Keyhooks
*/
int		keyhook_handler(t_data *data);
int		close_button(t_data *data);
int		mouse_press(int button, int x, int y, t_data *data);
int		mouse_release(int button, int x, int y, t_data *data);
int		key_press(int keystroke, t_data *data);
int		key_release(int keystroke, t_data *data);

/*
** Player
*/
int		player_movement(t_data *data);
int		player_rotation(t_data *data);
int		modify_stamina(t_data *data);
/*
** Enemy
*/
int		enemy_sprite_casting(t_data *data);
void	enemy_anim_cycle(t_data *data);
int		count_enemies(t_data *data);
void	enemy_setup(t_data *data);
void	enemy_actions(t_data *data);
void	setup_rat(t_data *data, t_enemy *enemy, int x, int y);
void	setup_goblin(t_data *data, t_enemy *enemy, int x, int y);
/*
** Interface
*/
void	draw_weapon(t_data *data);
void	draw_mouse(t_data *data);
/*
** Parse color
*/


/*
** Draw image
*/
void	draw_view(t_data *data);
void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int 	*load_texture(t_data *data, char *path);
void	draw_ver_line(int i, t_data *data);

#endif