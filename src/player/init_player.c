/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:42:03 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/30 19:20:28 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "player.h"
#include "types.h"

static bool	set_player_orientation(t_player *player);
static bool	set_movment_rotation(t_player *player);

bool	initialize_player(t_map *map, t_player *player)
{
	if (!init_def_player(player))
		return (ft_dprintf(STDERR_FILENO, "ERROR :default initialzation\n"),
			false);
	if (!get_player_pos_dir(map, player))
		return (ft_dprintf(STDERR_FILENO, "ERROR: Invalid direction\n"), false);
	if (!set_player_orientation(player))
		return (ft_dprintf(STDERR_FILENO,
				"ERROR initialize player orientation\n"), false);
	if (!set_movment_rotation(player))
		return (ft_dprintf(STDERR_FILENO,
				"ERROR initialize player movment and rotation speed\n"), false);
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
