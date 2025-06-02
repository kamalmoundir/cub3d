/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:02:06 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/02 18:10:12 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "types.h"

typedef struct s_ray
{
	t_vec2	direction;// ray direction (rayDirX, rayDirY)
	t_vec2	side_dist;
	t_vec2	delta_dist;
	int		step_x;// step direction in x (-1 or 1)
	int		step_y;
	int		map_x;// current grid cell in x
	int		map_y;
	int		side;// side of the wall hit (0 = vertical, 1 = horizontal)
	double	perp_wall_dist;// perpendicular distance to the wall
	double	wall_x;// wall hit position for texturing
}			t_ray;

// ray_setup.c
void		init_ray(t_player *player, t_ray *ray, int x, int screenWidth);

// raycasting_dda.c
bool		perform_dda(t_map *map, t_ray *ray, t_error *error);

// raycasting_utils.c
void		calculate_wall_distance(t_player *player, t_ray *ray);

// initialize ray struct with default values
bool		init_def_ray(t_ray *ray);

#endif