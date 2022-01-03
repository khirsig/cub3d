/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhagedor <jhagedor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:10:47 by jhagedor          #+#    #+#             */
/*   Updated: 2022/01/03 13:18:43 by jhagedor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

typedef struct s_texture {
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
}				t_texture;

#endif