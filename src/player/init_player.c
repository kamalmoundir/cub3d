/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:42:03 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/02 14:05:28 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "player.h"
#include "types.h"

//static bool	set_player_dir(t_player *player);
//static bool	set_player_pos(t_player *player);
static bool	set_player_orientation(t_player *player);
static bool	set_movment_rotation(t_player *player);

bool	initialize_player(t_map *map, t_player *player)
{
	if (!init_def_player(player))
		return (printf("ERROR :default initialzation\n"), false);
	if (!get_player_pos_dir(map, player))
		return (printf("ERROR: Invalid direction\n"), false);
	if (!set_player_orientation(player))
		return (printf("ERROR initialize player orientation\n"), false);
	if (!set_movment_rotation(player))
		return (printf("ERROR initialize player movment and rotation speed\n"),
			false);
	return (true);
}

static bool	set_player_orientation(t_player *player)
{
	if (!player)
		return (false);
	if (player->init_dir == 'N')
	{
		player->direction = (t_vec2){0, -1};
		player->plane = (t_vec2){0.66, 0};
	}
	else if (player->init_dir == 'S')
	{
		player->direction = (t_vec2){0, 1};
		player->plane = (t_vec2){-0.66, 0};
	}
	else if (player->init_dir == 'E')
	{
		player->direction = (t_vec2){1, 0};
		player->plane = (t_vec2){0, 0.66};
	}
	else if (player->init_dir == 'W')
	{
		player->direction = (t_vec2){-1, 0};
		player->plane = (t_vec2){0, -0.66};
	}
	else
		return (false);
	printf("player_init_dir: %c, x: %f, y: %f\n", player->init_dir, player->direction.x, player->direction.y);
	return (true);
}

static bool	set_movment_rotation(t_player *player)
{
	if (!player)
		return (false);
	player->move_speed = 0.05;
	player->rot_speed = 0.03;
	if (player->move_speed == 0 || player->rot_speed == 0)
		return (false);
	return (true);
}

/*
static bool	set_player_dir(t_player *player)
{
	if (!player)
		return (false);
	if (player->init_dir == 'N')
	{
		player->direction.x = 0;
		player->direction.y = -1;
	}
	else if (player->init_dir == 'S')
	{
		player->direction.x = 0;
		player->direction.y = 1;
	}
	else if (player->init_dir == 'E')
	{
		player->direction.x = 1;
		player->direction.y = 0;
	}
	else if (player->init_dir == 'W')
	{
		player->direction.x = -1;
		player->direction.y = 0;
	}
	else
		return (false);
	return (true);
}

static bool	set_player_pos(t_player *player)
{
	if (!player)
		return (false);
	if (player->init_dir == 'N')
	{
		player->plane.x = 0.66;
		player->plane.y = 0;
	}
	else if (player->init_dir == 'S')
	{
		player->plane.x = -0.66;
		player->plane.y = 0;
	}
	else if (player->init_dir == 'E')
	{
		player->plane.x = 0;
		player->plane.y = 0.66;
	}
	else if (player->init_dir == 'W')
	{
		player->plane.x = 0;
		player->plane.y = -0.66;
	}
	else
		return (false);
	return (true);
}*/

