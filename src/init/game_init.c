#include "game.h"
#include "file_parser.h"

static bool init_game_defaults(t_game *game);
static bool finalize_game_setup(t_game *game);
static bool	init_mlx_wrapper(t_mlx *mlx_wrapper);

bool init_game_with_file(t_game *game, const char *map_file)
{
    t_parse_result result;
    
    if (!init_game_defaults(game))
        return (false);
    result = parse_cub_file(map_file);
    if (!result.success)
    {
        if (result.error_msg)
        {
            set_error(&game->error, result.error_msg, 1);
            free(result.error_msg);
        }
        return (false);
    }
    game->map = result.map;
    game->config = result.config;
    if (!finalize_game_setup(game))
        return (false);
    if (!initialize_player(&game->map, &game->player))
    {
        set_error(&game->error, "Failed to initialize player", 1);
        cleanup_game(game);
        return (false);
    }
    return (true);
}


static bool init_game_defaults(t_game *game)
{
    game->error.message = NULL;
    game->error.code = 0;
    game->running = true;
    game->last_frame_time = get_time_ms();
    game->frame_time = 0.0;
    return (true);
}

static bool finalize_game_setup(t_game *game)
{
    if (!init_mlx_wrapper(&game->mlx))
    {
        set_error(&game->error, "Failed to initialize MLX", 1);
        return (false);
    }
    
    if (!load_all_textures(game))
    {
        set_error(&game->error, "Failed to load textures", 1);
        return (false);
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