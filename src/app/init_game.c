#include <math.h>
#include "types.h"
#include "player.h"
#include "map.h"
#include "ray.h"
#include "utils.h"
#include "game.h"

static bool init_player(t_player *player);
static bool	init_map(t_map *map);

bool	init_game(t_game *game)
{
	t_error	*error;

	error = malloc(sizeof(t_error));
	if (!error)
		return (false);
	error->message = NULL;
	error->code = 0;
	game->error = *error; // revise logic later, is it correct dereferencing in this context?
	if (!init_player(&game->player))
	{
		set_error(&game->error, "Failed to initialize player", 1);
		return (false);
	}
	if (!init_map(&game->map))
	{
		set_error(&game->error, "Failed to initialize map", 2);
	}
	game->running = true;
	// PLACEHOLDER
	// Initialize rest of objects here as well
	// PLACEHOLDER
	return (true);
}

static bool init_player(t_player *player) // example only, will feed from parser later
{
	player->position.x = 2.5;
	player->position.y = 2.5;
	player->direction.x = -1.0;
	player->direction.y = 0.0;
	player->plane.x = 0.0;
	player->plane.y = 0.66;
	return (true);
}

static bool	init_map(t_map *map) // refactor later and connect to parser
{
	static int worldMap[mapWidth][mapHeight]=
	{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	int	i;
	int	j;

	map->width = mapWidth;
	map->height = mapHeight;
	map->grid = malloc(map->height * sizeof(int *));
	if (!map->grid)
		return (false);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		map->grid[i] = malloc(map->width * sizeof(int));
		if (!map->grid[i]) // improve the error handling later, refactor it into separate function
		{
			while (j < i)
			{
				safe_free((void **)&map->grid[j]);
				j++;
			}
			safe_free((void **)map->grid);
			return (false);
		}
		while (j < map->width)
		{
			map->grid[i][j] = grid[i][j];
			j++;
		}
		i++;
	}
	return (true);
}