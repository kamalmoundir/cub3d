#ifndef GAME_H
# define GAME_H

# include "types.h"

typedef struct	s_game
{
	t_mlx			mlx;
	t_player		player;
	t_ray			ray;
	t_map			map;
	t_textures		textures;
	t_config		config;
	t_keys			keys;
	t_render_data	render;
	t_error			error;
	bool			running;
}	t_game;

// dda.c
void	perform_dda(t_map *map, t_ray *ray, t_error *error);

// init_game.c
bool	init_game(t_game *game);

// clean_central.c
void	cleanup_game(t_game *game);

#endif