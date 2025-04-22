#ifndef CONFIG_H
# define CONFIG_H

# include "types.h"

typedef struct	s_config
{
	char	*map_path;
	char	*texture_north_path;
	char	*texture_south_path;
	char	*texture_east_path;
	char	*texture_west_path;
	int		floor_color;
	int		ceiling_color;
}	t_config;

#endif