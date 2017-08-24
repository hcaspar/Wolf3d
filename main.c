/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 11:46:13 by hcaspar           #+#    #+#             */
/*   Updated: 2017/01/14 15:56:38 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_mlx		*init_data(void)
{
	t_mlx	*data;

	data = (t_mlx*)malloc(sizeof(t_mlx));
	if (data == NULL)
		exit_prog(data, "Malloc error");
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit_prog(data, "Mlx error");
	data->win = mlx_new_window(data->mlx_ptr, MAX_X, MAX_Y, "Wolf3D");
	if (data->win == NULL)
		exit_prog(data, "Mlx error");
	data->buf = init_image(data, MAX_X, SCREEN_Y);
	data->minimap = init_image(data, MAP_DIM, MAP_DIM);
	data->fps = 1;
	return (data);
}

void		tab_to_list(t_map *map, char *line, t_mlx *data)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[i])
		i++;
	map->n = i;
	map->i = (int*)malloc(sizeof(int) * i);
	if (map->i == NULL)
		exit_prog(data, "Malloc error");
	i = -1;
	while (tab[++i])
		map->i[i] = ft_atoi(tab[i]);
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void		loop(t_mlx *data, t_map *map)
{
	t_map	*tmp;

	tmp = data->map;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = map;
}

void		get_map(char *av, t_mlx *data)
{
	char	*line;
	int		fd;
	t_map	*map;

	data->map = NULL;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		exit_prog(data, "Open error");
	while (get_next_line(fd, &line) > 0)
	{
		map = (t_map*)malloc(sizeof(t_map));
		if (map == NULL)
			exit_prog(data, "Malloc error");
		map->next = NULL;
		if (data->map == NULL)
			data->map = map;
		else
			loop(data, map);
		tab_to_list(map, line, data);
		if (line)
			free(line);
	}
	if (close(fd) == -1)
		exit_prog(data, "Close error");
}

int			main(int ac, char **av)
{
	t_mlx	*data;

	data = NULL;
	if (ac < 2)
		disp_param(data);
	data = init_data();
	if (MAX_X < 800 || MAX_Y < 600)
		exit_prog(data, "Window's resolution is too low\n");
	get_map(av[1], data);
	data->grid = create_grid(data);
	init_player(data);
	init_info(data);
	mlx_hook(data->win, 2, (1L << 0), key_press, data);
	mlx_hook(data->win, 3, (1L << 0), key_release, data);
	mlx_hook(data->win, 6, (1L << 6), motion_notify, data);
	mlx_hook(data->win, 17, (1L << 17), red_cross, data);
	mlx_loop_hook(data->mlx_ptr, redraw, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
