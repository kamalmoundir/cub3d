#ifndef TYPES_H
# define TYPES_H

# include <stdbool.h>
# include "../libft/include/libft.h"

typedef struct s_game			t_game;
typedef struct s_mlx			t_mlx;
typedef struct s_player			t_player;
typedef struct s_map			t_map;
typedef struct s_config			t_config;
typedef struct s_keys			t_keys;
typedef struct s_render_data	t_render_data;
typedef struct s_textures		t_textures;

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;


typedef struct s_config
{
	bool	is_done;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	time;
	double	oldTime;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
}	t_config;

#endif