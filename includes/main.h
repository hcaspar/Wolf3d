/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 11:56:40 by hcaspar           #+#    #+#             */
/*   Updated: 2017/08/24 14:22:44 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../libft/includes/libft.h"
# include "../includes/get_next_line.h"
# include "keys.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# define MAX_X 1280
# define MAX_Y 1024
# define BLOCK_SIZE (MAX_Y / 4) / 15
# define MAP_DIM (MAX_Y / 4)
# define SCREEN_Y (MAX_Y - MAP_DIM)
# define BLUE 1
# define RED 2
# define YELLOW 3
# define GREEN 4

typedef struct		s_coor
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
}					t_coor;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct		s_map
{
	int				*i;
	int				n;
	struct s_map	*next;
}					t_map;

typedef struct		s_player
{
	double			movespeed;
	double			rotspeed;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				xstep;
	int				ystep;
	int				hit;
	int				side;
	double			perpwalldist;
	double			xdeltadist;
	double			ydeltadist;
	double			xdeltaside;
	double			ydeltaside;
	double			xsidedist;
	double			ysidedist;
	int				xmap;
	int				ymap;
	double			xraypos;
	double			yraypos;
	double			xraydir;
	double			yraydir;
	double			xcamera;
	double			time;
	double			oldtime;
	double			frametime;
	double			xplane;
	double			yplane;
	double			xdir;
	double			ydir;
	double			xpos;
	double			ypos;
}					t_player;

typedef struct		s_disp
{
	void			*image;
	char			*string;
	int				bpp;
	int				size_line;
	int				endian;
}					t_disp;

typedef struct		s_info
{
	int				right;
	int				left;
	int				fwd;
	int				back;
	int				rotright;
	int				rotleft;
}					t_info;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win;
	t_map			*map;
	int				**grid;
	t_player		player;
	t_color			color;
	int				square;
	int				curs_pos;
	t_disp			minimap;
	t_disp			buf;
	int				fps;
	t_info			info;
}					t_mlx;

void				raycast_loop(t_mlx *data);
void				info_loop(t_mlx *data);
void				init_info(t_mlx *data);
void				init_player_pos(t_mlx *data);
void				init_player(t_mlx *data);
t_disp				init_image(t_mlx *data, int x, int y);
void				draw_square_blue(t_mlx *data, int i, int j);
void				draw_square_red(t_mlx *data, int i, int j);
void				draw_square_yellow(t_mlx *data, int i, int j);
void				draw_square_green(t_mlx *data, int i, int j);
void				draw_mini_map(t_mlx *data);
void				disp_param(t_mlx *data);
void				exit_prog(t_mlx *data, char *msg);
int					key_release(int keycode, t_mlx *data);
int					key_press(int keycode, t_mlx *data);
int					motion_notify(int x, int y, t_mlx *data);
int					red_cross(t_mlx *data);
void				verline(int x, int start, int end, t_mlx *data);
t_player			move_fwd(t_mlx *data, t_player player);
t_player			move_bck(t_mlx *data, t_player player);
t_player			move_lft(t_mlx *data, t_player player);
t_player			move_rgt(t_mlx *data, t_player player);
t_player			rotate_right(t_player player);
t_player			rotate_left(t_player player);
int					redraw(t_mlx *data);
void				erase_win(t_mlx *data);
int					check_hit(t_mlx *data, int x, int y);
void				get_color(t_mlx *data);
int					**create_grid(t_mlx *data);

#endif
