#include "types.h"
#include "utils.h"
#include "map.h"
#include "game.h"

void	cleanup_game(t_game *game)
{
	int	i;
	i = 0;
	if (game->map.grid)
	{
		while (i < game->map.height)
			safe_free((void **)&game->map.grid[i]);
		safe_free((void **)&game->map.grid);
	}
	if (game->error.message)
		safe_free((void **)&game->error.message);
	// PLACEHOLDER
	// Add cleanup for other resources
	// PLACEHOLDER
}