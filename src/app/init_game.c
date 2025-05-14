#include <math.h>
#include "game.h"


static bool	init_mlx_wrapper(t_mlx *mlx_wrapper);

bool	init_game(t_game *game)
{
	char		**data_raw;

	game->error.message = NULL;
	game->error.code = 0;
	data_raw = get_raw_lines("assets/maps/map1.cub");
	if (!data_raw)
	{
		set_error(&game->error, "Failed to load map file", 1);
		return (false);
	}
    init_def_map(&game->map);
    if (!init_map(&game->map, data_raw, "assets/maps/map1.cub"))
	{
		set_error(&game->error, "Failed to extract map", 1);
		free_array(data_raw);
		cleanup_game(game);
		return (false);
	}
    init_def_config(&game->config);
	if (!init_config(&game->config, data_raw))
    {
        set_error(&game->error, "Config extraction failed", 1);
		free_array(data_raw);
		cleanup_game(game);
        return (false);
    }
	free_array(data_raw);
	if (!init_mlx_wrapper(&game->mlx))
	{
		set_error(&game->error, "Failed to initialize mlx_wrapper", 1);
		cleanup_game(game);
		return (false);
	}
	if (!initialize_player(&game->map, &game->player))
	{
		set_error(&game->error, "Failed to initialize player", 1);
		cleanup_game(game);
		return (false);
	}
	game->running = true;
	game->last_frame_time = get_time_ms();
	game->frame_time = 0.0;
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
	{
		mlx_destroy_display(mlx_wrapper->mlx_ptr);
		safe_free((void **)&mlx_wrapper->mlx_ptr);
		return (false);
	}
	mlx_wrapper->img_ptr = mlx_new_image(mlx_wrapper->mlx_ptr, mlx_wrapper->width, mlx_wrapper->height);
	if (!mlx_wrapper->img_ptr)
	{
		mlx_destroy_window(mlx_wrapper->mlx_ptr, mlx_wrapper->win_ptr);
		mlx_destroy_display(mlx_wrapper->mlx_ptr);
		safe_free((void **)&mlx_wrapper->mlx_ptr);
		return (false);
	}
	mlx_wrapper->img_data = mlx_get_data_addr(mlx_wrapper->img_ptr,
			&(mlx_wrapper->bpp),
			&(mlx_wrapper->line_len),
			&(mlx_wrapper->endian));
	return (true);
}