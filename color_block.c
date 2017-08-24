/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 13:31:53 by hcaspar           #+#    #+#             */
/*   Updated: 2017/08/24 14:25:43 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		get_color(t_mlx *data)
{
	if (data->square == BLUE)
	{
		data->color.b = 255;
		data->color.g = 0;
		data->color.r = 0;
	}
	if (data->square == RED)
	{
		data->color.b = 0;
		data->color.g = 0;
		data->color.r = 255;
	}
	if (data->square == YELLOW)
	{
		data->color.b = 0;
		data->color.g = 255;
		data->color.r = 255;
	}
	if (data->square == GREEN)
	{
		data->color.b = 0;
		data->color.g = 255;
		data->color.r = 0;
	}
}

void		draw_square_blue(t_mlx *data, int i, int j)
{
	int		x;
	int		y;

	y = 0;
	while (y < BLOCK_SIZE)
	{
		x = 0;
		while (x < BLOCK_SIZE)
		{
			data->minimap.string[(x + i * BLOCK_SIZE) * 4 + \
					(y + j * BLOCK_SIZE) * data->minimap.size_line] = 127;
			data->minimap.string[(x + i * BLOCK_SIZE) * 4 + \
					(y + j * BLOCK_SIZE) * data->minimap.size_line + 1] = 0;
			data->minimap.string[(x + i * BLOCK_SIZE) * 4 + \
					(y + j * BLOCK_SIZE) * data->minimap.size_line + 2] = 0;
			data->minimap.string[(x + i * BLOCK_SIZE) * 4 + \
					(y + j * BLOCK_SIZE) * data->minimap.size_line + 3] = 0;
			x++;
		}
		y++;
	}
}

void		draw_square_red(t_mlx *data, int i, int j)
{
	int		x;
	int		y;

	y = 0;
	while (y < BLOCK_SIZE)
	{
		x = 0;
		while (x < BLOCK_SIZE)
		{
			data->minimap.string[(x + i * BLOCK_SIZE) * 4 + \
					(y + j * BLOCK_SIZE) * data->minimap.size_line] = 0;
			data->minimap.string[(x + i * BLOCK_SIZE) * 4 + \
					(y + j * BLOCK_SIZE) * data->minimap.size_line + 1] = 0;
			data->minimap.string[(x + i * BLOCK_SIZE) * 4 + \
					(y + j * BLOCK_SIZE) * data->minimap.size_line + 2] = 127;
			data->minimap.string[(x + i * BLOCK_SIZE) * 4 + \
					(y + j * BLOCK_SIZE) * data->minimap.size_line + 3] = 0;
			x++;
		}
		y++;
	}
}

void		draw_square_yellow(t_mlx *data, int i, int j)
{
	int		x;
	int		y;

	y = 0;
	while (y < BLOCK_SIZE)
	{
		x = 0;
		while (x < BLOCK_SIZE)
		{
			data->minimap.string[(x + i * BLOCK_SIZE) * 4 + \
					(y + j * BLOCK_SIZE) * data->minimap.size_line] = 0;
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

void		draw_square_green(t_mlx *data, int i, int j)
{
	int		x;
	int		y;

	y = 0;
	while (y < BLOCK_SIZE)
	{
		x = 0;
		while (x < BLOCK_SIZE)
		{
			data->minimap.string[(x + i * BLOCK_SIZE) * 4 + \
					(y + j * BLOCK_SIZE) * data->minimap.size_line] = 0;
			data->minimap.string[(x + i * BLOCK_SIZE) * 4 + \
					(y + j * BLOCK_SIZE) * data->minimap.size_line + 1] = 127;
			data->minimap.string[(x + i * BLOCK_SIZE) * 4 + \
					(y + j * BLOCK_SIZE) * data->minimap.size_line + 2] = 0;
			data->minimap.string[(x + i * BLOCK_SIZE) * 4 + \
					(y + j * BLOCK_SIZE) * data->minimap.size_line + 3] = 0;
			x++;
		}
		y++;
	}
}
