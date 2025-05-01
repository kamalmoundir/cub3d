/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:59:51 by kmoundir          #+#    #+#             */
/*   Updated: 2025/04/29 11:53:39 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TYPES_H
# define TYPES_H

# include <stdbool.h>
# include "../library/libft/libft.h"

# define CUB3D_MAP_WIDTH 24
# define CUB3D_MAP_HEIGHT 24
# define CUB3D_SCREEN_WIDTH 640
# define CUB3D_SCREEN_HEIGHT 480

typedef struct s_game			t_game;
//typedef struct s_mlx			t_mlx;
typedef struct s_player			t_player;
typedef struct s_ray			t_ray;
typedef struct s_map			t_map;
typedef struct s_config			t_config;
typedef struct s_keys			t_keys;
typedef struct s_render_data	t_render_data;
typedef struct s_textures		t_textures;
typedef struct s_color			t_color;

typedef struct	s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct	s_error 
{
	char	*message;
	int		code;
}	t_error;

#endif