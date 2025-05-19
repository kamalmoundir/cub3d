#ifndef MLX_WRAPPER_H
# define MLX_WRAPPER_H

# include <math.h>
# include "../lib/minilibx-linux/mlx.h"
# include "game.h"
# include "types.h"

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
