/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstoev <sstoev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:57:19 by sstoev            #+#    #+#             */
/*   Updated: 2025/05/13 15:57:20 by sstoev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <X11/keysym.h>
#include "game.h"
#include "ray.h"
#include "utils.h"
#include "player.h"
#include "render.h"
#include "mlx_wrapper.h"
#include "map.h"

static int	game_loop(t_game *game);

int	main(int argc, char **argv)
{
	t_game		game;
	t_map		*map;
	t_config	*config;
	char		**data_raw;

	if(!validate_input("assets/maps/map1.cub"))
    {
        printf("error");
        return (-1);
    }
	data_raw = get_raw_lines("assets/maps/map1.cub");
	map = malloc(sizeof(t_map));
	if(!init_def_map(map))
    {
        return (-1);
    }
    ft_extract_map(data_raw, map);
	config = malloc(sizeof(t_config));
    if(!init_def_config(config))
        return(-1);
    if (!extract_config(data_raw, config)) 
    {
        printf("Config extraction failed\n");
        return (1);
    }
	ft_memset(&game, 0, sizeof(t_game));
	if (!init_game(&game))
	{
		ft_dprintf(STDERR_FILENO, "Failed to initialize game\n");
		return (EXIT_FAILURE);
	}
	//printf("player_init_dir: %c, x: %f, y: %f\n", game.player.init_dir, game.player.position.x, game.player.position.y);
//	printf("floor-r: %d, floor-g: %d, floor-b: %d\n", game.config.floor_color.r, game.config.floor_color.g, game.config.floor_color.b);
//	printf("config-W: %s\n", game.config.west_texture);
	ft_print_str(game.map.grid);
	mlx_hook(game.mlx.win_ptr, 2, 1L<<0, key_press, &game);
	mlx_hook(game.mlx.win_ptr, 3, 1L<<1, key_release, &game);
	mlx_hook(game.mlx.win_ptr, 17, 0, close_window, &game);
	mlx_loop_hook(game.mlx.mlx_ptr, game_loop, &game);
	mlx_loop(game.mlx.mlx_ptr);
	cleanup_game(&game);
	return (0);
}

static int	game_loop(t_game *game)
{
	if (!game->running)
	{
		mlx_loop_end(game->mlx.mlx_ptr);
		return (1);
	}
	update_player(game);

	debug_render(game);
	printf("player_init_dir: %c, x: %0.2f, y: %0.2f\n", game->player.init_dir, game->player.position.x, game->player.position.y);
	render_frame(game);
	return (0);
}
