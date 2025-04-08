#ifndef GAME_H
# define GAME_H

# include "types.h"

struct s_game
{
	t_mlx			mlx;
	t_player		player;
	t_map			map;
	t_textures		textures;
	t_config		config;
	t_keys			keys;
	t_render_data	render;
	bool			running;
}	t_game;

#endif