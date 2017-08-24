/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 17:22:44 by hcaspar           #+#    #+#             */
/*   Updated: 2016/09/07 17:47:45 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_player	move_fwd(t_mlx *data, t_player player)
{
	if (!check_hit(data, (int)(player.xpos + player.xdir * player.movespeed), \
			(int)player.ypos))
		player.xpos += player.xdir * player.movespeed;
	if (!check_hit(data, (int)(player.xpos), \
			(int)(player.ypos + player.ydir * player.movespeed)))
		player.ypos += player.ydir * player.movespeed;
	return (player);
}

t_player	move_bck(t_mlx *data, t_player player)
{
	if (!check_hit(data, (int)(player.xpos - player.xdir * player.movespeed), \
			(int)player.ypos))
		player.xpos -= player.xdir * player.movespeed;
	if (!check_hit(data, (int)(player.xpos), \
			(int)(player.ypos - player.ydir * player.movespeed)))
		player.ypos -= player.ydir * player.movespeed;
	return (player);
}

t_player	move_lft(t_mlx *data, t_player player)
{
	if (!check_hit(data, (int)(player.xpos + player.ydir * player.movespeed), \
			(int)player.ypos))
		player.xpos += player.ydir * player.movespeed;
	if (!check_hit(data, (int)(player.xpos), \
			(int)(player.ypos - player.xdir * player.movespeed)))
		player.ypos -= player.xdir * player.movespeed;
	return (player);
}

t_player	move_rgt(t_mlx *data, t_player player)
{
	if (!check_hit(data, (int)(player.xpos - player.ydir * player.movespeed), \
			(int)player.ypos))
		player.xpos -= player.ydir * player.movespeed;
	if (!check_hit(data, (int)(player.xpos), \
			(int)(player.ypos + player.xdir * player.movespeed)))
		player.ypos += player.xdir * player.movespeed;
	return (player);
}
