/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:43:16 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/17 13:14:04 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

typedef struct s_vars {
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	char	*addr;
	int		**texture;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	xmax;
	double	xmin;
	double	ymax;
	double	ymin;
}				t_vars;

#endif