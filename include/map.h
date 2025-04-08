#ifndef MAP_H
# define MAP_H

#include "types.h"

typedef struct s_map
{
	int	width;
	int	height;
	int	**grid;
}	t_map;

#endif