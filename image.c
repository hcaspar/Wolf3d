/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:06:07 by hcaspar           #+#    #+#             */
/*   Updated: 2017/01/14 15:06:50 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_disp			init_image(t_mlx *data, int x, int y)
{
	t_disp		tmp;

	tmp.image = mlx_new_image(data->mlx_ptr, x, y);
	if (tmp.image == NULL)
		exit_prog(data, "Mlx error");
	tmp.string = mlx_get_data_addr(tmp.image, &tmp.bpp, &tmp.size_line, \
								&tmp.endian);
	if (tmp.string == NULL)
		exit_prog(data, "Mlx error");
	return (tmp);
}

void			erase_win(t_mlx *data)
{
	if (data->buf.image)
	{
		mlx_destroy_image(data->mlx_ptr, data->buf.image);
		data->buf = init_image(data, MAX_X, SCREEN_Y);
	}
	if (data->minimap.image)
	{
		mlx_destroy_image(data->mlx_ptr, data->minimap.image);
		data->minimap = init_image(data, MAP_DIM, MAP_DIM);
	}
}
