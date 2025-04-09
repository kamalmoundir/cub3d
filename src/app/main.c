#include <stdlib.h>
#include "game.h"
#include "ray.h"
#include "utils.h"
#include "player.h"
#include "mlx_wrapper.h"
#include "map.h"

// below is just for testing concepts/ understanding, hence not part of actual implementation 

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_game	game;

	if (!init_game(&game))
	{
		ft_dprintf(STDERR_FILENO, "Failed to initialize game\n");
		return (EXIT_FAILURE);
	}
	while (game.running)
	{
		perform_dda(&game.map, &game.ray, &game.error);
		if (game.error.message)
			set_error(&game.error, "Unable to perform dda", EXIT_FAILURE);
		// PLACEHOLDER
		// Update game state and render frame
		// PLACEHOLDER
	}
	cleanup_game(&game);
	return (0);
}