/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:50:35 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/02 15:03:14 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "render.h"
#include <math.h>

static bool	init_mlx_wrapper(t_mlx *mlx_wrapper);
static bool	init_map_config(t_game *game, char *file);
static void	init_game_helper(t_game *game);

bool	init_game(t_game *game, char *file)
{
	init_game_helper(game);
	if (!init_map_config(game, file))
	{
		return (false);
	}
	if (!init_mlx_wrapper(&game->mlx))
	{
		set_error(&game->error, "Failed to initialize mlx_wrapper", 1);
		cleanup_game(game);
		return (false);
	}
	if (!load_all_textures(game))
	{
		set_error(&game->error, "Failed to load textures", 1);
		cleanup_game(game);
		return (false);
	}
	if (!initialize_player(&game->map, &game->player))
	{
		set_error(&game->error, "Failed to initialize player", 1);
		cleanup_game(game);
		return (false);
	}
	return (true);
}

static void	init_game_helper(t_game *game)
{
	game->error.message = NULL;
	game->error.code = 0;
	game->running = true;
	game->last_frame_time = get_time_ms();
	game->frame_time = 0.0;
}

static bool	init_map_config(t_game *game, char *file)
{
	char	**data_raw;

	init_def_map(&game->map);
	init_def_config(&game->config);
	data_raw = get_raw_lines(file);
	if (!data_raw)
	{
		set_error(&game->error, "Failed to load map file", 1);
		return (false);
	}
	if (!init_map(&game->map, data_raw, file))
	{
		set_error(&game->error, "Failed to extract map", 1);
		cleanup_game(game);
		return (free_array(data_raw), false);
	}
	if (!init_config(&game->config, data_raw))
	{
		set_error(&game->error, "Config extraction failed", 1);
		cleanup_game(game);
		return (free_array(data_raw), false);
	}
	free_array(data_raw);
	return (true);
}

static bool	init_mlx_img(t_mlx *mlx_wrapper)
{
	mlx_wrapper->img_ptr = mlx_new_image(mlx_wrapper->mlx_ptr,
			mlx_wrapper->width, mlx_wrapper->height);
	if (!mlx_wrapper->img_ptr)
	{
		mlx_destroy_window(mlx_wrapper->mlx_ptr, mlx_wrapper->win_ptr);
		mlx_destroy_display(mlx_wrapper->mlx_ptr);
		mlx_wrapper->mlx_ptr = NULL;
		return (false);
	}
	mlx_wrapper->img_data = mlx_get_data_addr(mlx_wrapper->img_ptr,
			&(mlx_wrapper->bpp), &(mlx_wrapper->line_len),
			&(mlx_wrapper->endian));
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
			mlx_wrapper->width, mlx_wrapper->height, "cub3d");
	if (!mlx_wrapper->win_ptr)
	{
		mlx_destroy_display(mlx_wrapper->mlx_ptr);
		mlx_wrapper->mlx_ptr = NULL;
		return (false);
	}
	if (!init_mlx_img(mlx_wrapper))
		return (false);
	return (true);
}
