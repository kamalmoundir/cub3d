#ifndef RENDER_H
# define RENDER_H

# include "types.h"

typedef struct	s_render_data
{
	double	camera_x;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	double	tex_pos;
	double	tex_step;
	int		tex_y;
	int		color;
	int		side;
	double	wall_x;
}	t_render_data;

// render_buffer.c
void	clear_buffer(t_game *game);
void	draw_floor_ceiling(t_game *game);

// render_core.c
bool	cast_all_rays(t_game *game);

// render_utils.c
void	draw_vertical_line(t_game *game, int x, t_line line, int color);
int		select_wall_color(t_game *game, t_ray *ray);

// render_walls.c
void	draw_wall_slice(t_game *game, int x);

#endif