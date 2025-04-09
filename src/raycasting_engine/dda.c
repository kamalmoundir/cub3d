#include "types.h"
#include "player.h"
#include "ray.h"
#include "map.h"
#include "utils.h"

void	perform_dda(t_map *map, t_ray *ray, t_error *error)
{
	int	hit;

	hit = 0;
	while (!hit)
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
			set_error(error, "Raycasting out of bounds");
			return ;
		}
		if (map->grid[ray->mapX][ray->mapY])
			hit = 1;
	}
}