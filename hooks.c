/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 13:17:32 by hcaspar           #+#    #+#             */
/*   Updated: 2017/01/14 16:51:35 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		info_loop(t_mlx *data)
{
	if (data->info.fwd)
		data->player = move_fwd(data, data->player);
	if (data->info.back)
		data->player = move_bck(data, data->player);
	if (data->info.right)
		data->player = move_rgt(data, data->player);
	if (data->info.left)
		data->player = move_lft(data, data->player);
	if (data->info.rotright)
		data->player = rotate_right(data->player);
	if (data->info.rotleft)
		data->player = rotate_left(data->player);
}

int			key_release(int keycode, t_mlx *data)
{
	if (keycode == RIGHT)
		data->info.rotright = 0;
	if (keycode == LEFT)
		data->info.rotleft = 0;
	if (keycode == W)
		data->info.fwd = 0;
	if (keycode == S)
		data->info.back = 0;
	if (keycode == D)
		data->info.right = 0;
	if (keycode == A)
		data->info.left = 0;
	return (0);
}

int			key_press(int keycode, t_mlx *data)
{
	if (keycode == ESC)
		exit_prog(data, NULL);
	if (keycode == RIGHT)
		data->info.rotright = 1;
	if (keycode == LEFT)
		data->info.rotleft = 1;
	if (keycode == W)
		data->info.fwd = 1;
	if (keycode == S)
		data->info.back = 1;
	if (keycode == D)
		data->info.right = 1;
	if (keycode == A)
		data->info.left = 1;
	if (keycode == F && data->fps == 0)
		data->fps = 1;
	else if (keycode == F && data->fps == 1)
		data->fps = 0;
	return (0);
}

int			motion_notify(int x, int y, t_mlx *data)
{
	if (x > data->curs_pos)
		data->player = rotate_right(data->player);
	else
		data->player = rotate_left(data->player);
	data->curs_pos = x;
	y = 0;
	return (0);
}

int			red_cross(t_mlx *data)
{
	exit_prog(data, NULL);
	return (0);
}
