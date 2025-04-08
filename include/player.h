#ifndef PLAYER_H
# define PLAYER_H

#include "types.h"

typedef struct	s_player
{
	t_vec2	position;
	t_vec2	direction;
	double	speed;
}	t_player;

#endif