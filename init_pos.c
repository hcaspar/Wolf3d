/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 19:42:35 by hcaspar           #+#    #+#             */
/*   Updated: 2017/01/14 16:05:49 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		init_player_pos(t_mlx *data)
{
	t_map	*tmp;
	int		i;
	int		j;

	tmp = data->map;
	j = 0;
	while (tmp)
	{
		i = 0;
		while (i != tmp->n && tmp->i[i] != 5)
			i++;
		if (tmp->i[i] == 5)
		{
			data->player.xpos = i;
			data->player.ypos = j;
		}
		j++;
		tmp = tmp->next;
	}
	if (data->player.xpos == -1 || data->player.ypos == -1)
		exit_prog(data, "No player start");
}

void		init_player(t_mlx *data)
{
	data->player.xplane = 0.66;
	data->player.yplane = 0;
	data->player.xdir = 0;
	data->player.ydir = -1;
	data->player.xpos = -1;
	data->player.ypos = -1;
	data->player.time = 1;
	data->player.oldtime = 0;
	data->player.frametime = 0.014;
	init_player_pos(data);
	data->player.movespeed = 0.056;
	data->player.rotspeed = 0.028;
	data->curs_pos = MAX_X / 2;
}

void		init_info(t_mlx *data)
{
	data->info.right = 0;
	data->info.left = 0;
	data->info.fwd = 0;
	data->info.back = 0;
	data->info.rotright = 0;
	data->info.rotleft = 0;
}
