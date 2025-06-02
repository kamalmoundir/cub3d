/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:36:23 by sstoev            #+#    #+#             */
/*   Updated: 2025/06/02 18:17:48 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "ray.h"
#include "types.h"
#include <math.h>

static void	calculate_ray_direction(t_player *player, t_ray *ray,
				double cameraX);
static void	calculate_delta_dist(t_ray *ray);
static void	calculate_step_and_side_dist(t_player *player, t_ray *ray);

void	init_ray(t_player *player, t_ray *ray, int x, int screenWidth)
{
	double	camera_x;

	camera_x = 2 * x / (double)screenWidth - 1;
	ray->map_x = (int)player->position.x;
	ray->map_y = (int)player->position.y;
	calculate_ray_direction(player, ray, camera_x);
	calculate_delta_dist(ray);
	calculate_step_and_side_dist(player, ray);
}

static void	calculate_ray_direction(t_player *player, t_ray *ray,
		double camera_x)
{
	ray->direction.x = player->direction.x + player->plane.x * camera_x;
	ray->direction.y = player->direction.y + player->plane.y * camera_x;
}

static void	calculate_delta_dist(t_ray *ray)
{
	double	inv_dir_x;
	double	inv_dir_y;

	if (ray->direction.x != 0)
	{
		inv_dir_x = 1.0 / ray->direction.x;
		ray->delta_dist.x = fabs(inv_dir_x);
	}
	else
		ray->delta_dist.x = INFINITY;
	if (ray->direction.y != 0)
	{
		inv_dir_y = 1.0 / ray->direction.y;
		ray->delta_dist.y = fabs(inv_dir_y);
	}
	else
		ray->delta_dist.y = INFINITY;
}

static void	calculate_step_and_side_dist(t_player *player, t_ray *ray)
{
	if (ray->direction.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist.x = (player->position.x - ray->map_x)
			* ray->delta_dist.x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist.x = (ray->map_x + 1.0 - player->position.x)
			* ray->delta_dist.x;
	}
	if (ray->direction.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist.y = (player->position.y - ray->map_y)
			* ray->delta_dist.y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist.y = (ray->map_y + 1.0 - player->position.y)
			* ray->delta_dist.y;
	}
}
