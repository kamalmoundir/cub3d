/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:37:11 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/02 14:38:26 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../library/MLX42/include/MLX42/MLX42.h"
# include "../library/libft/libft.h"
# include "config.h"
# include "map.h"
# include "player.h"
# include "ray.h"
# include "types.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	int			width;
	int			height;
	t_config	*config;
	t_player	*player;
	t_ray		*ray;

	t_map		*map;

}				t_game;


char			**copy_map(char **map, int rows);
void			free_array(char **str);
int				validate_extension(char *s);
void			path_finder(char **map, int x, int y);
int				check_unreacheble_area(t_map *map);
int				get_number_line_file(char *filepath);
char			**get_raw_lines(char *filepath);
bool			is_map_line(const char *line);
bool			ft_extract_map(char **raw_lines, t_map *map);
int				is_empty_line(const char *line);
bool			validate_input(char *path);
void			safe_free(void **ptr);
bool init_def_game(t_game *game);
#endif
