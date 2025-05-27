#ifndef DEBUG_H
# define DEBUG_H

# include "game.h"

void debug_game_state(t_game *game);
void debug_mlx_state(t_mlx *mlx);
void debug_map_state(t_map *map);
void debug_player_state(t_player *player);
void debug_config_state(t_config *config);
void debug_textures_state(t_textures *textures);
bool validate_game_initialization(t_game *game);

#endif