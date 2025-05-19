#include "types.h"
#include "utils.h"
#include "map.h"
#include "game.h"

void	cleanup_game(t_game *game)
{
	int	i;

	i = 0;
	if (!game)
		return ;
	if (game->map.grid)
	{
		while (i < game->map.height)
		{
			safe_free((void **)&game->map.grid[i]);
			i++;
		}
		safe_free((void **)&game->map.grid);
	}
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
	if (game->error.message)
		safe_free((void **)&game->error.message);
	game->running = false;
}