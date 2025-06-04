/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:30:00 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/04 12:32:54 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "types.h"
# include <fcntl.h>

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}			t_color;

typedef struct s_config
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	t_color	floor_color;
	t_color	ceiling_color;
}			t_config;

// Function prototypes
int			parse_color(char *line, t_color *color);
int			parse_texture_path(char *line, char **texture_path);
int			parse_config_line(char *line, t_config *config);

// derify if files of texture exist
bool		verify_texture_file(char *texture_path);
int			rgb_to_int(t_color color);

// initialize cinfig struct by default value
bool		init_def_config(t_config *config);
bool		init_config(t_config *config, char **data_raw);
bool		validate_config(t_config *config);
bool		extract_config(char **raw_lines, t_config *config);
void		free_config(t_config *config);
int			ft_is_number(const char *s);

#endif