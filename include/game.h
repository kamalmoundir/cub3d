#ifndef GAME_H
# define GAME_H

# include "mlx_wrapper.h"
# include "player.h"
# include "ray.h"
# include "map.h"
# include "utils.h"
# include "config.h"
# include "render.h"
# include "types.h"

typedef struct	s_game
{
	t_mlx			mlx;
	t_player		player;
	t_ray			ray;
	t_map			map;
	t_config		config;
	t_textures		textures;
	t_keys			keys;
	t_render_data	render;
	t_error			error;
	bool			running;
}	t_game;

typedef struct s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
}	t_keys;

typedef struct s_textures
{
	void	*wall_n;
	void	*wall_s;
	void	*wall_e;
	void	*wall_w;
	void	*wall_n_data;
	void	*wall_s_data;
	void	*wall_e_data;
	void	*wall_w_data;
	int		width;
	int		height;
}	t_textures;


// dda.c
void	perform_dda(t_map *map, t_ray *ray, t_error *error);

// init_game.c
bool	init_game(t_game *game);

// clean_central.c
void	cleanup_game(t_game *game);

#endif