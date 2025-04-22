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

#endif