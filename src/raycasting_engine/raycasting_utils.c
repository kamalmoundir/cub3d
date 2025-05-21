/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 22:46:35 by sstoev            #+#    #+#             */
/*   Updated: 2025/05/21 11:58:49 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "types.h"
#include "player.h"
#include "ray.h"

void	calculate_wall_distance(t_player *player, t_ray *ray)
{
	if (ray->side == 0)
		ray->perpWallDist = (ray->mapX - player->position.x + (1 - ray->stepX) / 2) / ray->direction.x;
	else
		ray->perpWallDist = (ray->mapY - player->position.y + (1 - ray->stepY) / 2) / ray->direction.y;
	if (ray->side == 0)
		ray->wallX = player->position.y + ray->perpWallDist * ray->direction.y;
	else
		ray->wallX = player->position.x + ray->perpWallDist * ray->direction.x;
	ray->wallX -= floor(ray->wallX);
}
