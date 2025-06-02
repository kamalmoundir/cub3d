/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs_default_val.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:49:27 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/02 18:11:57 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "game.h"
#include "map.h"
#include "player.h"

bool	init_def_player(t_player *player)
{
	if (!player)
		return (false);
	player->direction.x = -1;
	player->direction.y = -1;
	player->position.x = -1;
	player->position.y = -1;
	player->plane.x = -1;
	player->plane.y = -1;
	player->init_dir = '\0';
	player->move_speed = 0.05;
	player->rot_speed = 0.03;
	player->move_forward = 0;
	player->move_sideways = 0;
	player->rotate = 0;
	player->health = 100;
	player->stamina = 100;
	player->has_key = false;
	player->score = 0;
	return (true);
}

bool	init_def_map(t_map *map)
{
	if (!map)
		return (false);
	map->copy_grid = NULL;
	map->grid = NULL;
	map->height = 0;
	map->width = 0;
	map->path = NULL;
	map->error.code = 0;
	map->error.message = NULL;
	return (true);
}

bool	init_def_config(t_config *config)
{
	if (!config)
		return (false);
	config->north_texture = NULL;
	config->south_texture = NULL;
	config->west_texture = NULL;
	config->east_texture = NULL;
	config->floor_color = (t_color){-1, -1, -1};
	config->ceiling_color = (t_color){-1, -1, -1};
	return (true);
}

bool	init_def_ray(t_ray *ray)
{
	if (!ray)
		return (false);
	ray->delta_dist.x = 0;
	ray->delta_dist.y = 0;
	ray->direction.x = 0;
	ray->direction.y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->perp_wall_dist = 0;
	ray->side_dist.x = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side = 0;
	ray->wall_x = 0;
	return (true);
}
