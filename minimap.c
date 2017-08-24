/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 10:26:31 by hcaspar           #+#    #+#             */
/*   Updated: 2017/08/24 14:26:53 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			draw_player(t_mlx *data, int i, int j)
{
	int			y;
	int			x;

	y = BLOCK_SIZE / 4 - 1;
	while (y != BLOCK_SIZE - BLOCK_SIZE / 4)
	{
		x = BLOCK_SIZE / 4 - 1;
		while (x != BLOCK_SIZE - BLOCK_SIZE / 4)
		{
			data->minimap.string[(x + i * BLOCK_SIZE) * 4 + \
					(y + j * BLOCK_SIZE) * data->minimap.size_line] = 127;
			data->minimap.string[(x + i * BLOCK_SIZE) * 4 + \
					(y + j * BLOCK_SIZE) * data->minimap.size_line + 1] = 127;
			data->minimap.string[(x + i * BLOCK_SIZE) * 4 + \
					(y + j * BLOCK_SIZE) * data->minimap.size_line + 2] = 127;
			data->minimap.string[(x + i * BLOCK_SIZE) * 4 + \
					(y + j * BLOCK_SIZE) * data->minimap.size_line + 3] = 0;
			x++;
		}
		y++;
	}
}

void			draw_square(t_mlx *data, t_coor coor, int i, int j)
{
	int			**tmp;
	t_map		*tmp2;
	int			x;

	x = -1;
	tmp2 = data->map;
	while (tmp2 && ++x < coor.y1)
		tmp2 = tmp2->next;
	if (tmp2 == NULL || coor.y1 < 0 || coor.x1 < 0 || coor.x1 >= tmp2->n)
		return ;
	tmp = data->grid;
	if (coor.x1 == (int)data->player.xpos && coor.y1 == (int)data->player.ypos)
		draw_player(data, i, j);
	if (tmp[coor.y1][coor.x1] == BLUE)
		draw_square_blue(data, i, j);
	if (tmp[coor.y1][coor.x1] == RED)
		draw_square_red(data, i, j);
	if (tmp[coor.y1][coor.x1] == YELLOW)
		draw_square_yellow(data, i, j);
	if (tmp[coor.y1][coor.x1] == GREEN)
		draw_square_green(data, i, j);
}

void			draw_mini_map(t_mlx *data)
{
	t_coor		coor;
	int			i;
	int			j;

	j = 0;
	coor.y1 = (int)data->player.ypos - 7;
	coor.y2 = (int)data->player.ypos + 8;
	coor.x2 = (int)data->player.xpos + 8;
	while (coor.y1 != coor.y2)
	{
		i = 0;
		coor.x1 = (int)data->player.xpos - 7;
		while (coor.x1 != coor.x2)
		{
			draw_square(data, coor, i, j);
			coor.x1++;
			i++;
		}
		coor.y1++;
		j++;
	}
}
