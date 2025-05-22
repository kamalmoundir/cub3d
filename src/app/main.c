/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:57:19 by sstoev            #+#    #+#             */
/*   Updated: 2025/05/22 17:31:03 by kmoundir         ###   ########.fr       */
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
	char		*file;
	t_config	*config;
	char		**data_raw;

	(void)argc;
	data_raw =NULL;
	
	
	file = ft_strtrim(argv[1], " ");
	config = malloc(sizeof(t_config));
   
	if(!validate_input(file))
    {
        printf("error");
		free(file);
        return (-1);
    }
	data_raw = get_raw_lines(file);
	map = malloc(sizeof(t_map));
	if(!init_def_map(map)){
        return (-1);
	}
    ft_extract_map(data_raw, map);

 if(!init_def_config(config))
        return(-1);
	
	ft_memset(&game, 0, sizeof(t_game));
	if (!init_game(&game))
	{
		cleanup_game(&game);
		ft_dprintf(STDERR_FILENO, "Failed to initialize game\n");
		return (EXIT_FAILURE);
	}
	free_array(data_raw);
	//printf("player_init_dir: %c, x: %f, y: %f\n", game.player.init_dir, game.player.position.x, game.player.position.y);
//	printf("floor-r: %d, floor-g: %d, floor-b: %d\n", game.config.floor_color.r, game.config.floor_color.g, game.config.floor_color.b);
//	printf("config-W: %s\n", game.config.west_texture);
	ft_print_str(game.map.grid);
	mlx_hook(game.mlx.win_ptr, 2, 1L<<0, key_press, &game);
	mlx_hook(game.mlx.win_ptr, 3, 1L<<1, key_release, &game);
	mlx_hook(game.mlx.win_ptr, 17, 0, close_window, &game);
	mlx_loop_hook(game.mlx.mlx_ptr, game_loop, &game);
	mlx_loop(game.mlx.mlx_ptr);
	//cleanup_game(&game);
	clean_up_all_resources(&game, map, config, data_raw);
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
