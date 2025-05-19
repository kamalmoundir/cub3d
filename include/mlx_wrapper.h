#ifndef MLX_WRAPPER_H
# define MLX_WRAPPER_H

# include <math.h>
# include "../lib/minilibx-linux/mlx.h"
# include "game.h"
# include "types.h"

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


typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_mlx;

#endif
