#ifndef PLAYER_H
# define PLAYER_H

#include "types.h"

typedef struct	s_player
{
	t_vec2	position; // player's position (posX, posY)
	t_vec2	direction; // player's direction vector (dirX, dirY)
	t_vec2	plane; // Camera plane for FOV
	double	speed;
}	t_player;

#endif