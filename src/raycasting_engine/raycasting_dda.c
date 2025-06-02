/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_dda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:27:36 by sstoev            #+#    #+#             */
/*   Updated: 2025/06/02 18:14:02 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "player.h"
#include "ray.h"
#include "types.h"
#include "utils.h"

static bool	dda_step(t_map *map, t_ray *ray, int *hit, t_error *error);

bool	perform_dda(t_map *map, t_ray *ray, t_error *error)
{
	int	hit;
	int	iter;
	int	max_iter;

	hit = 0;
	iter = 0;
	max_iter = max_int(map->width, map->height) * 2;
	while (!hit && iter < max_iter)
	{
		if (!dda_step(map, ray, &hit, error))
			return (false);
		iter++;
	}
	if (iter >= max_iter)
	{
		set_error(error, "DDA reached iteration limit", 3);
		return (false);
	}
	return (true);
}

static bool	dda_step(t_map *map, t_ray *ray, int *hit, t_error *error)
{
	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->delta_dist.x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist.y += ray->delta_dist.y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
	if (ray->map_x < 0 || ray->map_x >= map->width || ray->map_y < 0
		|| ray->map_y >= map->height)
	{
		set_error(error, "Raycasting out of bounds", 2);
		return (false);
	}
	*hit = (map->grid[ray->map_y][ray->map_x] == '1');
	return (true);
}
