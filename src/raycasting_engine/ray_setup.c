/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstoev <sstoev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:36:23 by sstoev            #+#    #+#             */
/*   Updated: 2025/04/22 22:37:28 by sstoev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "types.h"
#include "player.h"
#include "ray.h"

static void	calculate_ray_direction(t_player *player, t_ray *ray, double cameraX);
static void	calculate_delta_dist(t_ray *ray);
static void calculate_step_and_side_dist(t_player *player, t_ray *ray);

void	init_ray(t_player *player, t_ray *ray, int x, int screenWidth)
{
	double	cameraX;

	cameraX = 2 * x / (double)screenWidth - 1;
	ray->mapX = (int)player->position.x;
	ray->mapY = (int)player->position.y;
	calculate_ray_direction(player, ray, cameraX);
	calculate_delta_dist(ray);
	calculate_step_and_side_dist(player, ray);
}

static void	calculate_ray_direction(t_player *player, t_ray *ray, double cameraX)
{
	ray->direction.x = player->direction.x + player->plane.x * cameraX;
	ray->direction.y = player->direction.y + player->plane.y * cameraX;
}

static void	calculate_delta_dist(t_ray *ray)
{
	double	inv_dir_x;
	double	inv_dir_y;

	if (ray->direction.x != 0)
	{
		inv_dir_x = 1.0 / ray->direction.x;
		ray->deltaDist.x = fabs(inv_dir_x);
	}
	else
		ray->deltaDist.x = INFINITY;
	if (ray->direction.y != 0)
	{
		inv_dir_y = 1.0 / ray->direction.y;
		ray->deltaDist.y = fabs(inv_dir_y);
	}
	else
		ray->deltaDist.y = INFINITY;
}

static void calculate_step_and_side_dist(t_player *player, t_ray *ray)
{
	if (ray->direction.x < 0)
	{
		ray->stepX = -1;
		ray->sideDist.x = (player->position.x - ray->mapX) * ray->deltaDist.x; // fractal part * distance between 2 vertical grids
	}
	else
	{
		ray->stepX = 1;
		ray->sideDist.x = (ray->mapX + 1.0 - player->position.x) * ray->deltaDist.x;
	}
	if (ray->direction.y < 0)
	{
		ray->stepY = -1;
		ray->sideDist.y = (player->position.y - ray->mapY) * ray->deltaDist.y; // fractal part * distance between 2 vertical grids
	}
	else
	{
		ray->stepY = 1;
		ray->sideDist.y = (ray->mapY + 1.0 - player->position.y) * ray->deltaDist.y;
	}
}
