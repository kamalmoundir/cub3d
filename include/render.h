#ifndef RENDER_H
# define RENDER_H

# include "types.h"

typedef struct	s_render_data
{
	int		screen_width;
	int		screen_height;
	double	*zbuffer; // for sprite drawing or depth shading
}	t_render_data;

#endif