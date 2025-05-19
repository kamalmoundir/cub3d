#ifndef RENDER_H
# define RENDER_H

# include "types.h"

typedef struct s_render_data
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
}			t_render_data;

typedef struct s_texture
{
    void *img;
    int  *data;
    int   width;
    int   height;
    int   bits_pixel;
    int   size_line;
    int   endian;
} t_texture;

typedef struct s_textures
{
    t_texture north;
    t_texture south;
    t_texture east;
    t_texture west;
} t_textures;

typedef struct s_texture_data
{
	t_texture	*texture;
	int			x;
	int			y;
}	t_texture_data;

// init_textures.c
bool		init_texture_default(t_texture *texture);
bool		init_all_textures_default(t_textures *txt);

// load_images.c
bool		load_all_textures(t_game *game);

// render_buffer.c
void		clear_buffer(t_game *game);
void		draw_floor_ceiling(t_game *game, t_line *wall_lines);

// render_core.c
void		render_frame(t_game *game);
bool		cast_all_rays(t_game *game, t_line *wall_lines);

// render_utils.c
void		draw_vertical_line(t_game *game, int x, t_line line, int color);

// render_walls.c
t_texture	*select_wall_texture(t_game *game, t_ray *ray);
void		calculate_wall_dimensions(t_game *game, int *line_height, t_line *wall_line);
int			calculate_texture_x(t_game *game, t_texture *texture);
void		draw_texture_pixel(t_game *game, int x, int y, t_texture_data *tex_data);
void		draw_textured_line(t_game *game, int x, t_line *line, t_texture *texture);
void		draw_wall_slice(t_game *game, int x);

#endif