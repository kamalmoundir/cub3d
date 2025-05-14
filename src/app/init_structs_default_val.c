/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs_default_val.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:49:27 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/01 18:56:36 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "map.h"
#include "player.h"
#include "game.h"

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
	ray->deltaDist.x = 0;
	ray->deltaDist.y = 0;
	ray->direction.x = 0;
	ray->direction.y = 0;
	ray->mapX = 0;
	ray->mapY = 0;
	ray->perpWallDist = 0;
	ray->sideDist.x = 0;
	ray->stepX = 0;
	ray->stepY = 0;
	ray->side = 0;
    ray->wallX = 0;
    return (true);
}


