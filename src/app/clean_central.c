/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_central.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:40:48 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/30 16:40:51 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "map.h"
#include "types.h"
#include "utils.h"

static void	free_mlx_pointer(t_game *game);

void	cleanup_game(t_game *game)
{
	int	i;

	i = -1;
	if (!game)
		return ;
	if (game->map.grid)
	{
		while (++i < game->map.height)
		{
			safe_free((void **)&game->map.grid[i]);
		}
		safe_free((void **)&game->map.grid);
	}
	free_config(&game->config);
	safe_free((void **)&game->map.path);
	free_mlx_pointer(game);
	if (game->error.message)
		safe_free((void **)&game->error.message);
	game->running = false;
}

void	clean_up_all_resources(t_game *game, t_map *map, t_config *config,
		char **data_raw)
{
	if (data_raw)
		free_array(data_raw);
	if (config)
		free_config(config);
	if (map)
	{
		safe_free((void **)&map->path);
		if (map->grid)
			free_array(map->grid);
		if (map->copy_grid)
			free_array(map->copy_grid);
	}
	if (game)
		cleanup_game(game);
}

static void	free_mlx_pointer(t_game *game)
{
	if (game->mlx.mlx_ptr)
	{
		if (game->mlx.img_ptr)
		{
			mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img_ptr);
			game->mlx.img_ptr = NULL;
		}
		if (game->mlx.win_ptr)
		{
			mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
			game->mlx.win_ptr = NULL;
		}
		if (game->textures.north.img)
			mlx_destroy_image(game->mlx.mlx_ptr, game->textures.north.img);
		if (game->textures.south.img)
			mlx_destroy_image(game->mlx.mlx_ptr, game->textures.south.img);
		if (game->textures.east.img)
			mlx_destroy_image(game->mlx.mlx_ptr, game->textures.east.img);
		if (game->textures.west.img)
			mlx_destroy_image(game->mlx.mlx_ptr, game->textures.west.img);
		mlx_destroy_display(game->mlx.mlx_ptr);
		safe_free((void **)&game->mlx.mlx_ptr);
	}
}
