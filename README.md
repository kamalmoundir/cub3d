# cub3D

A simple raycasting 3D engine inspired by *Wolfenstein 3D*, built in C.

## Features
- Raycasting renderer with textured walls
- Player movement + rotation
- Collision handling
- `.cub` map parsing
- Floor / Ceiling colors

## Requirements
- C compiler (`cc`/`clang`)
- `make`
- MiniLibX (and its OS-specific dependencies)

## Build
```bash
make
```

## Run
```bash
./cub3D <map.cub>
```

Example:
```bash
./cub3D maps/subject.cub
```

## Controls
- `W/A/S/D` — move
- `←/→` — rotate
- `ESC` — quit

> Update controls if you implemented mouse rotation, sprint, etc.

## Map format (`.cub`)

### Textures
```
NO ./path_to_north_texture.xpm
SO ./path_to_south_texture.xpm
WE ./path_to_west_texture.xpm
EA ./path_to_east_texture.xpm
```

### Colors
```
F 220,100,0
C 225,30,0
```

### Map layout
- `1` wall
- `0` empty space
- `N/S/E/W` player spawn

Example:
```
111111
100001
10N001
100001
111111
```

## License
MIT License.
