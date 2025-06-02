/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 22:46:35 by sstoev            #+#    #+#             */
/*   Updated: 2025/06/02 18:17:54 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "ray.h"
#include "types.h"
#include <math.h>

void	calculate_wall_distance(t_player *player, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - player->position.x + (1
					- ray->step_x) / 2) / ray->direction.x;
	else
		ray->perp_wall_dist = (ray->map_y - player->position.y + (1
					- ray->step_y) / 2) / ray->direction.y;
	if (ray->side == 0)
		ray->wall_x = player->position.y + ray->perp_wall_dist
			* ray->direction.y;
	else
		ray->wall_x = player->position.x + ray->perp_wall_dist
			* ray->direction.x;
	ray->wall_x -= floor(ray->wall_x);
}
