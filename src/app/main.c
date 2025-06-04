/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:57:19 by sstoev            #+#    #+#             */
/*   Updated: 2025/06/03 14:40:45 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "map.h"
#include "mlx_wrapper.h"
#include "player.h"
#include "ray.h"
#include "render.h"
#include "utils.h"
#include <X11/keysym.h>
#include <stdlib.h>

static int	game_loop(t_game *game);
static int	handle_init_error(t_game *game);
static void	run_game(t_game *game);
static bool	validate_args(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_game	game;
	char	*file;
	char	**data_raw;

	if (!validate_args(argc, argv))
		return (EXIT_FAILURE);
	file = ft_strtrim(argv[1], " ");
	if (!validate_input(file))
	{
		free(file);
		return (1);
	}
	ft_memset(&game, 0, sizeof(t_game));
	if (!init_game(&game, file))
	{
		handle_init_error(&game);
	}
	free(file);
	run_game(&game);
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
	render_frame(game);
	return (0);
}

static int	handle_init_error(t_game *game)
{
	cleanup_game(game);
	ft_dprintf(STDERR_FILENO, "Failed to initialize game\n");
	return (EXIT_FAILURE);
}

static bool	validate_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, "Usage: %s <map_file.cub>\n", argv[0]);
		return (false);
	}
	return (true);
}

static void	run_game(t_game *game)
{
	mlx_hook(game->mlx.win_ptr, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx.win_ptr, 3, 1L << 1, key_release, game);
	mlx_hook(game->mlx.win_ptr, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx.mlx_ptr, game_loop, game);
	mlx_loop(game->mlx.mlx_ptr);
}
