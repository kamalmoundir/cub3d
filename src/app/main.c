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

	if (argc != 2 || !argv[1])
		return (1);
	if(!validate_input("assets/maps/map1.cub"))
    {
        ft_printf("Failed to validate input\n");
        return (1);
    }
	ft_memset(&game, 0, sizeof(t_game));
	if (!init_game(&game))
	{
		ft_dprintf(STDERR_FILENO, "Failed to initialize game\n");
		return (EXIT_FAILURE);
	}
	printf("player_init_dir: %c, x: %f, y: %f\n", game.player.init_dir, game.player.position.x, game.player.position.y);
	printf("floor-r: %d, floor-g: %d, floor-b: %d\n", game.config.floor_color.r, game.config.floor_color.g, game.config.floor_color.b);
	printf("config-W: %s\n", game.config.west_texture);
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
	// debug_render(game);
	//printf("player_init_dir: %c, x: %f, y: %f\n", game->player.init_dir, game->player.position.x, game->player.position.y);
	render_frame(game);
	return (0);
}
