#ifndef RAY_H
# define RAY_H

# include "types.h"

typedef struct s_ray // temporary, updated for each column of the screen while raycasting
{
	t_vec2	direction; // ray direction (rayDirX, rayDirY)
	t_vec2	sideDist; // end value: distance to the next x or y side, value during calc: accummulated on each step 
	t_vec2	deltaDist; // distance between vertical or horizontal walls on the overall grid
	int		stepX; // step direction in x (-1 or 1)
	int		stepY;
	int		mapX; // current grid cell in x
	int		mapY;
	int		side; // side of the wall hit (0 = vertical, 1 = horizontal)
	double	perpWallDist; // perpendicular distance to the wall
	double	wallX; // wall hit position for texturing
}	t_ray;

// ray_setup.c
void	init_ray(t_player *player, t_ray *ray, int x, int screenWidth);

// raycasting_dda.c
bool	perform_dda(t_map *map, t_ray *ray, t_error *error);

// raycasting_utils.c
void	calculate_wall_distance(t_player *player, t_ray *ray);

#endif