/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_dda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:27:36 by sstoev            #+#    #+#             */
/*   Updated: 2025/05/21 11:58:45 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "player.h"
#include "ray.h"
#include "map.h"
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
	if (ray->sideDist.x < ray->sideDist.y)
	{
		ray->sideDist.x += ray->deltaDist.x;
		ray->mapX += ray->stepX;
		ray->side = 0;
	}
	else
	{
		ray->sideDist.y += ray->deltaDist.y;
		ray->mapY += ray->stepY;
		ray->side = 1;
	}
	if (ray->mapX < 0 || ray->mapX >= map->width
		|| ray->mapY < 0 || ray->mapY >= map->height)
	{
		set_error(error, "Raycasting out of bounds", 2);
		return (false);
	}
	*hit = (map->grid[ray->mapY][ray->mapX] == '1');
	return (true);
}