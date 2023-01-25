/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:20:54 by mraspors          #+#    #+#             */
/*   Updated: 2023/01/25 18:44:02 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <unistd.h>

#define MINIMAP_WIDTH 200
#define MINIMAP_HEIGHT 200

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

#define CELL_SIZE 20

#define PLAYER_MOVE_DIST 5

#define WALL_COLOR 0x0ABC00 // black
#define FLOOR_COLOR 0xFFFFFF // white
#define PLAYER_COLOR 0x012345
#define GRID_COLOR 0x000000

#define MAP_HEIGHT 9
#define MAP_WIDTH 29

#define INITIAL_PLAYER_ROW 1
#define INITIAL_PLAYER_COL 1

#define INITIAL_PLAYER_ORIENTATION 'N' // north

#define KEY_UP 13 // 'w' key
#define KEY_LEFT 0 // 'a' key
#define KEY_DOWN 1 // 's' key
#define KEY_RIGHT 2 // 'd' key
#define KEY_QUIT 53 // 'ESC' key

#define WIDTH 640
#define HEIGHT 480
#define FOV 60.0

typedef struct {
  double x;
  double y;
  double angle;
  double fov;
} Player;

typedef struct {
  double x;
  double y;
} Vec2;


typedef struct s_rgb {
	int		r;
	int		g;
	int		b;	
}				t_rgb;

typedef struct s_img
{
	void		*ptr;
	unsigned	*data;
	Vec2		size;
	double		aspect;
}	t_img;

typedef struct s_game {
	Vec2	player;
	double	angle;
	double	fov;
	int		i_pars;
	int		p_x;
	int		p_y;
	char	p_pos;
	int		w;
	int		h;
	char	*NO_texture;
	char	*SO_texture;
	char	*WE_texture;
	char	*EA_texture;
	char	*C_color;
	char	*F_color;
	char	**map_data;
	char	**map;
	t_rgb	C;
	t_rgb	F;
	t_img	*img;
	void	*mlx;
	void	*window;
}				t_game;

//===================Parsing=====================
void	read_check_map(char *s, t_game *game);
void	save_map_config(t_game *game);
void	check_map_config(t_game *game);
void	save_map(t_game *game);
void	map_fixer(t_game *game);
void	check_map_symbols_validity(t_game *game);
void	check_map_validity(t_game *game);
int		is_map_symbol(char c);
void	is_symbol_safe(t_game *game, int i, int j);
void	find_player(t_game *game);
//================================================


void	draw_minimap(t_game *game);
void	draw_grid(t_game *game);
void	draw_player(t_game *game);
void	erase_player(t_game *game);

void	free_if_er(t_game *game);

//---------FUCKING ZOZ-----------------
void init_game(t_game *game);
#endif