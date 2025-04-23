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
	t_render_data	render;
	t_error			error;
	double			last_frame_time;
	double			frame_time;
	int				floor_color;
	int				ceiling_color;
	bool			running;
	//t_textures		textures;
}	t_game;

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

// init_game.c
bool	init_game(t_game *game);

// input.c
int	key_press(int keycode, t_game *game);
int	key_release(int keycode, t_game *game);
int	close_window(t_game *game);

// clean_central.c
void	cleanup_game(t_game *game);

#endif