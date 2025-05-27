/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstoev <sstoev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:35:07 by sstoev            #+#    #+#             */
/*   Updated: 2025/05/27 16:35:08 by sstoev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "types.h"

typedef struct s_ray
{
	t_vec2	direction;
	t_vec2	sideDist;
	t_vec2	deltaDist;
	int		stepX;
	int		stepY;
	int		mapX;
	int		mapY;
	int		side;
	double	perpWallDist;
	double	wallX;
}	t_ray;

// ray_setup.c
void	init_ray(t_player *player, t_ray *ray, int x, int screenWidth);

// raycasting_dda.c
bool	perform_dda(t_map *map, t_ray *ray, t_error *error);

// raycasting_utils.c
void	calculate_wall_distance(t_player *player, t_ray *ray);

// initialize ray struct with default values 
bool	init_def_ray(t_ray *ray);

#endif
