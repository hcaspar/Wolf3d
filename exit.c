/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:17:16 by hcaspar           #+#    #+#             */
/*   Updated: 2017/01/14 14:33:34 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		disp_param(t_mlx *data)
{
	write(1, "Choose one of the map below :\n", 30);
	write(1, "\t-map\n", 6);
	exit_prog(data, NULL);
}

void		destroy_ptr(t_mlx *data)
{
	if (data->buf.image)
		mlx_destroy_image(data->mlx_ptr, data->buf.image);
	if (data->minimap.image)
		mlx_destroy_image(data->mlx_ptr, data->minimap.image);
	if (data->win)
		mlx_destroy_window(data->mlx_ptr, data->win);
}

void		exit_prog(t_mlx *data, char *msg)
{
	t_map	*tmp;

	if (data)
	{
		while (data->map)
		{
			if (data->map->i)
				free(data->map->i);
			tmp = data->map;
			data->map = data->map->next;
			free(tmp);
		}
		if (data->grid)
			free(data->grid);
		data->grid = NULL;
		destroy_ptr(data);
		free(data);
	}
	data = NULL;
	tmp = NULL;
	if (msg)
		write(2, msg, ft_strlen(msg));
	exit(0);
}
