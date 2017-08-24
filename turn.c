/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 17:20:22 by hcaspar           #+#    #+#             */
/*   Updated: 2016/09/07 21:17:34 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_player	rotate_left(t_player player)
{
	double	oldxdir;
	double	oldxplane;

	oldxdir = player.xdir;
	player.xdir = player.xdir * cos(-player.rotspeed) - \
		player.ydir * sin(-player.rotspeed);
	player.ydir = oldxdir * sin(-player.rotspeed) + \
		player.ydir * cos(-player.rotspeed);
	oldxplane = player.xplane;
	player.xplane = player.xplane * cos(-player.rotspeed) - \
		player.yplane * sin(-player.rotspeed);
	player.yplane = oldxplane * sin(-player.rotspeed) + \
		player.yplane * cos(-player.rotspeed);
	return (player);
}

t_player	rotate_right(t_player player)
{
	double	oldxdir;
	double	oldxplane;

	oldxdir = player.xdir;
	player.xdir = player.xdir * cos(player.rotspeed) - \
		player.ydir * sin(player.rotspeed);
	player.ydir = oldxdir * sin(player.rotspeed) + \
		player.ydir * cos(player.rotspeed);
	oldxplane = player.xplane;
	player.xplane = player.xplane * cos(player.rotspeed) - \
		player.yplane * sin(player.rotspeed);
	player.yplane = oldxplane * sin(player.rotspeed) + \
		player.yplane * cos(player.rotspeed);
	return (player);
}
