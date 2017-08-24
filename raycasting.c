/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 15:23:43 by hcaspar           #+#    #+#             */
/*   Updated: 2016/09/20 18:53:44 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		calc_steps(t_mlx *data)
{
	if (data->player.xraydir < 0)
	{
		data->player.xstep = -1;
		data->player.xsidedist = data->player.xdeltadist * \
			(data->player.xraypos - data->player.xmap);
	}
	else
	{
		data->player.xstep = 1;
		data->player.xsidedist = data->player.xdeltadist * \
			(data->player.xmap + 1.0 - data->player.xraypos);
	}
	if (data->player.yraydir < 0)
	{
		data->player.ystep = -1;
		data->player.ysidedist = data->player.ydeltadist * \
			(data->player.yraypos - data->player.ymap);
	}
	else
	{
		data->player.ystep = 1;
		data->player.ysidedist = data->player.ydeltadist * \
			(data->player.ymap + 1.0 - data->player.yraypos);
	}
}

int			check_hit(t_mlx *data, int x, int y)
{
	t_map	*tmp;

	tmp = data->map;
	while (tmp && y != 0)
	{
		tmp = tmp->next;
		y--;
	}
	if (tmp->i[x] > 0 && tmp->i[x] != 5)
	{
		return (tmp->i[x]);
	}
	return (0);
}

void		dda(t_mlx *data)
{
	while (data->player.hit == 0)
	{
		if (data->player.xsidedist < data->player.ysidedist)
		{
			data->player.xsidedist += data->player.xdeltadist;
			data->player.xmap += data->player.xstep;
			data->player.side = 0;
			data->square = RED;
			if (data->player.xstep == 1)
				data->square = GREEN;
		}
		else
		{
			data->player.ysidedist += data->player.ydeltadist;
			data->player.ymap += data->player.ystep;
			data->player.side = 1;
			data->square = BLUE;
			if (data->player.ystep == 1)
				data->square = YELLOW;
		}
		if (check_hit(data, data->player.xmap, data->player.ymap))
			data->player.hit = 1;
	}
}

void		init_ray_loop(t_mlx *data)
{
	data->player.xraypos = (double)data->player.xpos;
	data->player.yraypos = (double)data->player.ypos;
	data->player.xraydir = data->player.xdir + \
		data->player.xplane * data->player.xcamera;
	data->player.yraydir = data->player.ydir + \
		data->player.yplane * data->player.xcamera;
	data->player.xmap = (int)data->player.xraypos;
	data->player.ymap = (int)data->player.yraypos;
	data->player.xdeltadist = sqrt(1 + (data->player.yraydir * \
		data->player.yraydir) / (data->player.xraydir * data->player.xraydir));
	data->player.ydeltadist = sqrt(1 + (data->player.xraydir * \
		data->player.xraydir) / (data->player.yraydir * data->player.yraydir));
	data->player.hit = 0;
	calc_steps(data);
	dda(data);
}

void		raycast_loop(t_mlx *data)
{
	int		x;

	x = -1;
	while (++x < MAX_X)
	{
		data->player.xcamera = 2 * x / (double)MAX_X - 1;
		init_ray_loop(data);
		if (data->player.side == 0)
			data->player.perpwalldist = (data->player.xmap - \
				data->player.xraypos + (1 - data->player.xstep) / \
										2) / data->player.xraydir;
		else
			data->player.perpwalldist = (data->player.ymap - \
				data->player.yraypos + (1 - data->player.ystep) / \
										2) / data->player.yraydir;
		data->player.lineheight = (int)(SCREEN_Y / data->player.perpwalldist);
		data->player.drawstart = -data->player.lineheight / 2 + SCREEN_Y / 2;
		if (data->player.drawstart < 0)
			data->player.drawstart = 0;
		data->player.drawend = data->player.lineheight / 2 + SCREEN_Y / 2;
		if (data->player.drawend > SCREEN_Y || data->player.drawend < 0)
			data->player.drawend = SCREEN_Y;
		get_color(data);
		verline(x, data->player.drawstart, data->player.drawend, data);
	}
}
