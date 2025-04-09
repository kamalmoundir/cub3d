#ifndef CONFIG_H
# define CONFIG_H

# include "types.h"

typedef struct	s_config
{
	char	*texture_north;
	char	*texture_south;
	char	*texture_east;
	char	*texture_west;
	int		floor_color;
	int		ceiling_color;
}	t_config;

#endif