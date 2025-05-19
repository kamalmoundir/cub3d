/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:37:11 by kmoundir          #+#    #+#             */
/*   Updated: 2025/05/16 14:03:24 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include "mlx_wrapper.h"
# include "player.h"
# include "ray.h"
# include "map.h"
# include "utils.h"
# include "config.h"
# include "render.h"
# include "types.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

typedef struct	s_game
{
	t_mlx			mlx;
	t_player		player;
	t_ray			ray;
	t_map			map;
	t_config		config;
	t_render_data	render;
	t_error			error;
	double			last_frame_time;
	double			frame_time;
	bool			running;
	t_textures		textures;
}	t_game;


// init_game.c
bool	init_game(t_game *game);

// input.c
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
int		close_window(t_game *game);

// clean_central.c
void	cleanup_game(t_game *game);

char	**copy_map(char **map, int rows);
void	free_array(char **str);
int		validate_extension(char *s);
void	path_finder(char **map, int x, int y);
int		check_unreacheble_area(t_map *map);
int		get_number_line_file(char *filepath);
char	**get_raw_lines(char *filepath);
bool	is_map_line(const char *line);
bool	ft_extract_map(char **raw_lines, t_map *map);
int		is_empty_line(const char *line);
bool	validate_input(char *path);


#endif
