#ifndef FILE_PARSER_H
# define FILE_PARSER_H

#include "types.h"
#include "config.h"
#include "map.h"
#include "player.h"

typedef struct s_parse_result
{
    t_map		map;
    t_config	config;
    t_player	player;
    bool		success;
    char		*error_msg;
} t_parse_result;

// Main parsing function that uses your existing validation logic
t_parse_result  parse_cub_file(const char *filepath);

// Existing functions (declarations for clarity)
int		validate_extension(char *s);
char	**get_raw_lines(char *path);
bool	ft_extract_map(char **raw_lines, t_map *map);
bool	init_def_config(t_config *config);
bool	extract_config(char **data_raw, t_config *config);
bool	validate_config(t_config *config);
bool	get_player_pos_dir(t_map *map, t_player *player);
bool	map_valid_border(char **data_raw, t_map *map);
char	**copy_map(char **grid, int height);
int		get_map_hight(t_map *map);
void	path_finder(char **grid, int x, int y);
int		check_unreacheble_area(t_map *map);
void	free_config(t_config *config);
void	free_array(char **array);

#endif