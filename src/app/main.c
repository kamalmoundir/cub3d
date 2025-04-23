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
	t_game	game;

	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, "Allowed Format: %s <map_file.cub>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	ft_memset(&game, 0, sizeof(t_game));
	// if (!parse_arguments(argc, argv, &game))
	//	return (EXIT_FAILURE);
	if (!init_game(&game))
	{
		ft_dprintf(STDERR_FILENO, "Failed to initialize game\n");
		return (EXIT_FAILURE);
	}
	// print_grid(game.map.grid, game.map.height, game.map.width);
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
	//debug_render(game);
	render_frame(game);
	return (0);
}
