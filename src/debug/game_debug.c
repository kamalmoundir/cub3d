#include "game.h"
#include "utils.h"
#include "debug.h"

void debug_game_state(t_game *game)
{
    ft_printf("=== GAME STATE DEBUG ===\n");
    
    // Check basic game state
    ft_printf("Game running: %s\n", game->running ? "YES" : "NO");
    ft_printf("Frame time: %.3f\n", game->frame_time);
    ft_printf("Last frame time: %.3f\n", game->last_frame_time);
    
    // Check error state
    ft_printf("\n--- ERROR STATE ---\n");
    ft_printf("Error code: %d\n", game->error.code);
    ft_printf("Error message: %s\n", game->error.message ? game->error.message : "NULL");
    
    // Check MLX state
    debug_mlx_state(&game->mlx);
    
    // Check map state
    debug_map_state(&game->map);
    
    // Check player state
    debug_player_state(&game->player);
    
    // Check config state
    debug_config_state(&game->config);
    
    // Check textures state
    debug_textures_state(&game->textures);
    
    ft_printf("=== END DEBUG ===\n\n");
}

void debug_mlx_state(t_mlx *mlx)
{
    ft_printf("\n--- MLX STATE ---\n");
    ft_printf("MLX ptr: %p\n", mlx->mlx_ptr);
    ft_printf("Window ptr: %p\n", mlx->win_ptr);
    ft_printf("Screen width: %d\n", mlx->width);
    ft_printf("Screen height: %d\n", mlx->height);
}

void debug_map_state(t_map *map)
{
    int i, j;
    
    ft_printf("\n--- MAP STATE ---\n");
    ft_printf("Map width: %d\n", map->width);
    ft_printf("Map height: %d\n", map->height);
    ft_printf("Map grid ptr: %p\n", map->grid);
    ft_printf("Map copy_grid ptr: %p\n", map->copy_grid);
    ft_printf("Map path: %s\n", map->path ? map->path : "NULL");
    
    // Check if grid is properly allocated
    if (!map->grid)
    {
        ft_printf("ERROR: Map grid is NULL!\n");
        return;
    }
    
    if (map->width <= 0 || map->height <= 0)
    {
        ft_printf("ERROR: Invalid map dimensions!\n");
        return;
    }
    
    // Check first few rows of the grid
    ft_printf("First 3 rows of map:\n");
    for (i = 0; i < 3 && i < map->height; i++)
    {
        if (!map->grid[i])
        {
            ft_printf("ERROR: Map grid row %d is NULL!\n", i);
            continue;
        }
        ft_printf("Row %d: ", i);
        for (j = 0; j < map->width && j < 10; j++)  // Show first 10 columns
        {
            ft_printf("%d ", map->grid[i][j]);
        }
        ft_printf("\n");
    }
}

void debug_player_state(t_player *player)
{
    ft_printf("\n--- PLAYER STATE ---\n");
    ft_printf("Position: (%.3f, %.3f)\n", player->position.x, player->position.y);
    ft_printf("Direction: (%.3f, %.3f)\n", player->direction.x, player->direction.y);
    ft_printf("Plane: (%.3f, %.3f)\n", player->plane.x, player->plane.y);
    ft_printf("Move speed: %.3f\n", player->move_speed);
    ft_printf("Rotation speed: %.3f\n", player->rot_speed);
    ft_printf("Init dir: %c\n", player->init_dir);
    
    // Validate player position is within map bounds
    // Note: We'll need the map for this check
}

void debug_config_state(t_config *config)
{
    ft_printf("\n--- CONFIG STATE ---\n");
    ft_printf("North texture: %s\n", config->north_texture);
    ft_printf("South texture: %s\n", config->south_texture);
    ft_printf("East texture: %s\n", config->east_texture);
    ft_printf("West texture: %s\n", config->west_texture);
    ft_printf("Floor color: 0x%06X\n", config->floor_color);
    ft_printf("Ceiling color: 0x%06X\n", config->ceiling_color);
}

void debug_textures_state(t_textures *textures)
{
    ft_printf("\n--- TEXTURES STATE ---\n");
    ft_printf("North texture ptr: %p\n", textures->north);
    ft_printf("South texture ptr: %p\n", textures->south);
    ft_printf("East texture ptr: %p\n", textures->east);
    ft_printf("West texture ptr: %p\n", textures->west);
    
    ft_printf("North texture size: %dx%d\n", textures->north.width, textures->north.height);
	ft_printf("South texture size: %dx%d\n", textures->south.width, textures->south.height);
	ft_printf("East texture size: %dx%d\n", textures->east.width, textures->east.height);
	ft_printf("West texture size: %dx%d\n", textures->west.width, textures->west.height);
}

bool validate_game_initialization(t_game *game)
{
    bool valid = true;
    
    ft_printf("\n=== VALIDATION CHECK ===\n");
    
    // Check MLX
    if (!game->mlx.mlx_ptr || !game->mlx.win_ptr)
    {
        ft_printf("ERROR: MLX not properly initialized\n");
        valid = false;
    }
    
    // Check map
    if (!game->map.grid)
    {
        ft_printf("ERROR: Map grid is NULL\n");
        valid = false;
    }
    else if (game->map.width <= 0 || game->map.height <= 0)
    {
        ft_printf("ERROR: Invalid map dimensions: %dx%d\n", game->map.width, game->map.height);
        valid = false;
    }
    else
    {
        // Check if player position is within map bounds
        int player_x = (int)game->player.position.x;
        int player_y = (int)game->player.position.y;
        
        if (player_x < 0 || player_x >= game->map.width || 
            player_y < 0 || player_y >= game->map.height)
        {
            ft_printf("ERROR: Player position (%.2f, %.2f) is outside map bounds (%dx%d)\n",
                     game->player.position.x, game->player.position.y,
                     game->map.width, game->map.height);
            valid = false;
        }
        else if (game->map.grid[player_y][player_x] != 0)
        {
            ft_printf("ERROR: Player is positioned in a wall! Grid[%d][%d] = %d\n",
                     player_y, player_x, game->map.grid[player_y][player_x]);
            valid = false;
        }
    }
    
    // Check player direction vectors
    if (game->player.direction.x == 0 && game->player.direction.y == 0)
    {
        ft_printf("ERROR: Player direction vector is zero\n");
        valid = false;
    }
    
    if (game->player.plane.x == 0 && game->player.plane.y == 0)
    {
        ft_printf("ERROR: Player plane vector is zero\n");
        valid = false;
    }
    
    // Check textures
    if (!game->textures.north.data || !game->textures.south.data ||
        !game->textures.east.data || !game->textures.west.data)
    {
        ft_printf("ERROR: Textures not properly loaded\n");
        valid = false;
    }
    
    ft_printf("Validation result: %s\n", valid ? "PASSED" : "FAILED");
    ft_printf("=== END VALIDATION ===\n\n");
    
    return valid;
}