#ifndef MAP_H
# define MAP_H

#include "types.h"

typedef struct s_map
{
	int		**grid;
	int		width;
	int		height;
	char	*path;
}	t_map;

#endif