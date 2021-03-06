/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:44:54 by khirsig           #+#    #+#             */
/*   Updated: 2022/01/17 14:40:52 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAZE_H
# define MAZE_H

# include "texture.h"

typedef struct s_maze {
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	int			*door_texture;
	int			floor_color;
	int			ceiling_color;
	char		**map;
	t_texture	texture;
}				t_maze;

#endif