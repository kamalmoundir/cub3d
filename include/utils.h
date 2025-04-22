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
int	max_int(int a, int b);

#endif