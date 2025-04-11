/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:37:11 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/09 13:52:57 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../library/MLX42/include/MLX42/MLX42.h"
# include "../library/libft/libft.h"
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

typedef struct s_player
{
	int				pos_x;
	int				pos_y;
	char			init_dir;

}					t_player;

typedef struct s_colors
{
	int				red;
	int				green;
	int				blue;
}					t_colors;

typedef struct s_color_parser
{
	char			*ceiling_str;
	char			*floor_str;
	t_colors		ceiling;
	t_colors		floor;
	int				has_ceiling;
	int				has_floor;
}					t_color_parser;

typedef struct s_textures
{
	mlx_texture_t	*img;
	char			*path_texture;
	int				hight;
	int				width;
	int				*data;

}					t_textures;

typedef struct s_cub3d
{
	void			*mlx;
	void			*mlx_win;
	t_textures		textures[4];
	int				width;
	int				height;
	char			**map;

}					t_cub3d;

int					check_empty_line(t_cub3d *cub3d);
int					check_caracters(t_cub3d *cub);
int					check_multi_players(t_cub3d *cub);
int					check_borders(t_cub3d *cub);
// Updated parameter type from char **array to t_cub3d *cub
int					get_map_hight(t_cub3d *cub);
int					get_map_width(t_cub3d *cub);
// Updated parameter type from char **map to t_cub3d *cub
char				**copy_map(char **map, int rows);

int					check_borders(t_cub3d *cub);
void				free_array(char **str);
int					validate_extension(char *s);
void				path_finder(char **map, int x, int y);
t_player			get_player_pos_dir(t_cub3d *cub);
int					check_unreacheble_area(t_cub3d *cub);
char				**get_raw_line(char *str);

char				*get_next_line(int fd);
size_t				ft_strlcpy_gnl(char *dst, char *src, size_t size);
size_t				ft_strlcat_gnl(char *dst, char *src, size_t size);
char				*ft_substr_gnl(char const *s, unsigned int start,
						size_t len);
char				*ft_strjoin_gnl(char *s1, char *s2);
char				*ft_strchr_gnl(const char *s, int c);
char				*ft_get_line(int fd, char *line);
char				**array_map(int fd);

#endif
