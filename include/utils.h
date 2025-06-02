/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:01:26 by kmoundir          #+#    #+#             */
/*   Updated: 2025/06/02 18:02:53 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "error.h"
# include "game.h"

// memory_utils.c
void	safe_free(void **ptr);

// error_utils.c
void	set_error(t_error *error, const char *message, int code);
void	display_error(t_game *game);
void	clear_error(t_error *error);

// misc_utils.c
int		max_int(int a, int b);
double	get_time_ms(void);

// debug_utils.c
void	print_grid(int **grid, int height, int width);
void	debug_render(t_game *game);
void	ft_print_str(char **str);
#endif