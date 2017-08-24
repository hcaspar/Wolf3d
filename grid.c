/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 20:19:58 by hcaspar           #+#    #+#             */
/*   Updated: 2017/01/11 17:48:44 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int				find_grid_size(t_mlx *data)
{
	t_map		*tmp;
	int			i;

	tmp = data->map;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int				**create_grid(t_mlx *data)
{
	int			**grid;
	int			j;
	t_map		*tmp;

	tmp = data->map;
	grid = NULL;
	j = find_grid_size(data);
	grid = (int**)malloc(sizeof(int*) * (j + 1));
	grid[j] = NULL;
	j = 0;
	while (tmp)
	{
		grid[j] = tmp->i;
		j++;
		tmp = tmp->next;
	}
	return (grid);
}
