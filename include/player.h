#ifndef PLAYER_H
# define PLAYER_H

#include "types.h"

typedef struct	s_player
{
	t_vec2	position; // player's position (posX, posY)
	t_vec2	direction; // player's direction vector (dirX, dirY)
	t_vec2	plane; // Camera plane for FOV
	double	move_speed;
	double	rot_speed;
	int		health;
	int		stamina;
	bool	has_key;
	int		score;
	int		move_forward; // -1: backward, 0: none, 1: forward
	int		move_sideways; // -1: left, 0: node, 1: right;
	int		rotate; // -1: left, 0: none, 1: right
}	t_player;

// player_init.c
bool	init_player(t_player *player);

// player_movement.c
void	move_player_forward(t_game *game);
void	move_player_sideways(t_game *game);
void	rotate_player(t_game *game);

// player_collision.c
bool	is_wall(t_game *game, double x, double y);

// player_update.c
void	update_player(t_game *game);
void	update_movement_speed(t_game *game);

#endif