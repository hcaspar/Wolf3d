/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 13:57:11 by hcaspar           #+#    #+#             */
/*   Updated: 2017/01/14 16:45:10 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_disp			draw_roof(int start, int x, t_disp tmp)
{
	int			i;

	i = 0;
	if (start <= 0 || start > SCREEN_Y)
		return (tmp);
	while (i < start)
	{
		tmp.string[x * 4 + i * tmp.size_line] = 80;
		tmp.string[x * 4 + i * tmp.size_line + 1] = 80;
		tmp.string[x * 4 + i * tmp.size_line + 2] = 50;
		i++;
	}
	return (tmp);
}

t_disp			draw_floor(int end, int x, t_disp tmp)
{
	if (end <= 0 || end >= SCREEN_Y)
		return (tmp);
	while (end < SCREEN_Y)
	{
		tmp.string[x * 4 + end * tmp.size_line] = 105;
		tmp.string[x * 4 + end * tmp.size_line + 1] = 105;
		tmp.string[x * 4 + end * tmp.size_line + 2] = 105;
		end++;
	}
	return (tmp);
}

void			verline(int x, int start, int end, t_mlx *data)
{
	t_disp		tmp;

	tmp = data->buf;
	tmp = draw_roof(start, x, tmp);
	if (data->player.side == 1)
	{
		data->color.b /= 2;
		data->color.g /= 2;
		data->color.r /= 2;
	}
	while (start != end)
	{
		tmp.string[x * 4 + start * tmp.size_line] = data->color.b;
		tmp.string[x * 4 + start * tmp.size_line + 1] = data->color.g;
		tmp.string[x * 4 + start * tmp.size_line + 2] = data->color.r;
		start++;
	}
	tmp = draw_floor(end, x, tmp);
	data->buf = tmp;
}

void			draw_time(t_mlx *data)
{
	char		*tmp;

	tmp = NULL;
	data->player.oldtime = data->player.time;
	data->player.time = (double)clock();
	if (data->player.time == -1)
	{
		data->player.oldtime = 0;
		data->player.time = 1;
		return ;
	}
	data->player.frametime = (data->player.time - data->player.oldtime) \
		/ CLOCKS_PER_SEC;
	if (data->fps)
		tmp = ft_itoa((int)(1.0 / data->player.frametime));
	if (tmp && data->fps)
	{
		write(1, tmp, ft_strlen(tmp));
		write(1, "\n", 1);
		free(tmp);
	}
}

int				redraw(t_mlx *data)
{
	info_loop(data);
	raycast_loop(data);
	if (data->fps)
		draw_time(data);
	draw_mini_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win, \
							data->buf.image, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win, \
							data->minimap.image, 0, MAX_Y - MAX_Y / 4);
	erase_win(data);
	return (0);
}
