#include <stdlib.h>
#include <X11/keysym.h>
#include "game.h"
#include "ray.h"
#include "utils.h"
#include "player.h"
#include "mlx_wrapper.h"
#include "map.h"

static int	key_press(int keycode, t_game *game);
static int	key_release(int keycode, t_game *game);
static int	close_window(t_game *game);

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, "Allowed Format: %s <map_file.cub>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	ft_memset(&game, 0, sizeof(t_game));
	if (!parse_arguments(argc, argv, &game))
		return (EXIT_FAILURE);
	if (!init_game(&game))
	{
		ft_dprintf(STDERR_FILENO, "Failed to initialize game\n");
		return (EXIT_FAILURE);
	}
	mlx_hook(game.mlx.win_ptr, 2, 1L<<0, key_press, &game);
	mlx_hook(game.mlx.win_ptr, 3, 1L<<1, key_release, &game);
	mlx_hook(game.mlx.win_ptr, 17, 0, close_window, &game);
	game.running = true;
	while (game.running)
	{
		update_player(&game);
		render_frame(&game);
		perform_dda(&game.map, &game.ray, &game.error);
		if (game.error.message)
			set_error(&game.error, "Unable to perform dda", EXIT_FAILURE);
		mlx_loop_hook(game.mlx.mlx_ptr, NULL, &game);
	}
	cleanup_game(&game);
	return (0);
}

static int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->keys.w = true;
	else if (keycode == XK_a)
		game->keys.a = true;
	else if (keycode == XK_s)
		game->keys.s = true;
	else if (keycode == XK_d)
		game->keys.d = true;
	else if (keycode == XK_Left)
		game->keys.left = true;
	else if (keycode == XK_Right)
		game->keys.right = true;
	else if (keycode == XK_Escape)
		game->running = false;
	return (0);
}

static int	key_release(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->keys.w = false;
	else if (keycode == XK_a)
		game->keys.a = false;
	else if (keycode == XK_s)
		game->keys.s = false;
	else if (keycode == XK_d)
		game->keys.d = false;
	else if (keycode == XK_Left)
		game->keys.left = false;
	else if (keycode == XK_Right)
		game->keys.right = false;
	return (0);
}

static int	close_window(t_game *game)
{
	game->running = false;
	return (0);
}