#include <math.h>
#include "types.h"
#include "player.h"
#include "map.h"
#include "ray.h"
#include "utils.h"
#include "game.h"
#include "mlx_wrapper.h"

static bool	init_mlx_wrapper(t_mlx *mlx_wrapper);
static bool	init_map(t_map *map);

bool	init_game(t_game *game)
{
	game->error.message = NULL;
	game->error.code = 0;
	if (!init_mlx_wrapper(&game->mlx))
	{
		set_error(&game->error, "Failed to initialize mlx_wrapper", 1);
		return (false);
	}
	if (!init_player(&game->player))
	{
		set_error(&game->error, "Failed to initialize player", 1);
		return (false);
	}
	if (!init_map(&game->map))
	{
		set_error(&game->error, "Failed to initialize map", 1);
		return (false);
	}
	game->running = true;
	game->last_frame_time = get_time_ms();
	game->frame_time = 0.0;
	return (true);
}

static bool	init_map(t_map *map) // refactor later and connect to parser
{
	static int grid[CUB3D_MAP_WIDTH][CUB3D_MAP_HEIGHT]=
	{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	int	i;
	int	j;

	map->width = CUB3D_MAP_WIDTH;
	map->height = CUB3D_MAP_HEIGHT;
	map->grid = malloc(map->height * sizeof(int *));
	map->path = NULL;
	if (!map->grid)
		return (false);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		map->grid[i] = malloc(map->width * sizeof(int));
		if (!map->grid[i]) // improve the error handling later, refactor it into separate function
		{
			while (--i >= 0)
				safe_free((void **)&map->grid[i]);
			safe_free((void **)map->grid);
			return (false);
		}
		while (j < map->width)
		{
			map->grid[i][j] = grid[i][j];
			j++;
		}
		i++;
	}
	return (true);
}

static bool	init_mlx_wrapper(t_mlx *mlx_wrapper)
{
	mlx_wrapper->mlx_ptr = mlx_init();
	if (!mlx_wrapper->mlx_ptr)
		return (false);
	mlx_wrapper->height = CUB3D_SCREEN_HEIGHT;
	mlx_wrapper->width = CUB3D_SCREEN_WIDTH;
	mlx_wrapper->win_ptr = mlx_new_window(mlx_wrapper->mlx_ptr,
			mlx_wrapper->width,
			mlx_wrapper->height,
			"cub3d");
	if (!mlx_wrapper->win_ptr)
		return (false);
	mlx_wrapper->img_ptr = mlx_new_image(mlx_wrapper->mlx_ptr, mlx_wrapper->width, mlx_wrapper->height);
	if (!mlx_wrapper->img_ptr)
		return (false);
	mlx_wrapper->img_data = mlx_get_data_addr(mlx_wrapper->img_ptr,
			&(mlx_wrapper->bpp),
			&(mlx_wrapper->line_len),
			&(mlx_wrapper->endian));
	return (true);
}