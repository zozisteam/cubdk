/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:21:19 by mraspors          #+#    #+#             */
/*   Updated: 2023/01/25 18:32:32 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	print_data(t_game *game)
{
	printf("================RAW DATA=============\n");
	for (int i = 0; game->map_data[i] != NULL; i++)
		printf("%s\n", game->map_data[i]);
	printf("======================================\n\n");

	printf("=========TEXTURES & COLORS==========\n");
	printf("%s\n", game->NO_texture);
	printf("%s\n", game->SO_texture);
	printf("%s\n", game->WE_texture);
	printf("%s\n", game->EA_texture);
	printf("\n\n");
	printf("%s\n", game->C_color);
	printf("%s\n", game->F_color);
	printf("======================================\n\n");
}

void move_player(t_game *game, int direction) {
  if (direction == KEY_UP) 
  {
    if (game->map[(game->p_y - PLAYER_MOVE_DIST) / 20][game->p_x / 20] != '1')
      game->p_y -= PLAYER_MOVE_DIST;
  }
  else if (direction == KEY_DOWN)
  {
    if (game->p_y > 0 && game->map[(game->p_y + PLAYER_MOVE_DIST) / 20][game->p_x / 20] != '1')
      game->p_y += PLAYER_MOVE_DIST;
  }
  else if (direction == KEY_LEFT)
  {
    if (game->p_y > 0 && game->map[game->p_y / 20][(game->p_x - PLAYER_MOVE_DIST) / 20] != '1')
      game->p_x -= PLAYER_MOVE_DIST;
  }
  else if (direction == KEY_RIGHT)
  {
    if (game->p_y > 0 && game->map[game->p_y / 20][(game->p_x + PLAYER_MOVE_DIST) / 20] != '1')
      game->p_x += PLAYER_MOVE_DIST;
  }
}

int handle_key_press(int key, t_game *game) {
  erase_player(game);
  if (key == KEY_UP) {
    move_player(game, KEY_UP);
  } else if (key == KEY_DOWN) {
    move_player(game, KEY_DOWN);
  } else if (key == KEY_LEFT) {
    move_player(game, KEY_LEFT);
  } else if (key == KEY_RIGHT) {
    move_player(game, KEY_RIGHT);
  }
 draw_player(game);
 draw_grid(game);
  return 0;
}

void	check_file_name(int argc, char *s, t_game *game)
{
	char	*c;

	if (argc < 2)
	{
		printf("Error\nAdd map\n");
		free_if_er(game);
	}
	c = ft_strnstr(s, ".cub", ft_strlen(s));
	if (ft_strcmp(c, ".cub") != 0)
	{
		printf("Error\nExtension Error\n");
		free_if_er(game);
	}
}

void	init_struct(t_game *game)
{
	game->i_pars = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->w = 0;
	game->h = 0;
	game->map = NULL;
	game->map_data = NULL;
	game->NO_texture = NULL;
	game->SO_texture = NULL;
	game->WE_texture = NULL;
	game->EA_texture = NULL;
	game->C_color = NULL;
	game->F_color = NULL;
}

// Vec2 get_ray(double angle, double ray_angle) {
// 	angle = 0;
//     double sin_angle = sin(ray_angle);
//     double cos_angle = cos(ray_angle);
//     return (Vec2){cos_angle, sin_angle};
// }

// void move_player(t_game *game) {
//     game->angle += 0.01;
//     game->player.x += 1;
// }


// double get_wall_distance(Vec2 ray, Vec2 player, int *map_x, int *map_y, int *step_x, int *step_y) {
//     *map_x = player.x / 64;
//     *map_y = player.y / 64;
//     double delta_dist_x = fabs(1 / ray.x);
//     double delta_dist_y = fabs(1 / ray.y);
//     double wall_dist;
//     if (ray.x < 0) {
//         *step_x = -1;
//         wall_dist = (player.x - *map_x * 64) * delta_dist_x;
//     } else {
//         *step_x = 1;
//         wall_dist = (*map_x * 64 + 64 - player.x) * delta_dist_x;
//     }

//     if (ray.y < 0) {
//         *step_y = -1;
//         wall_dist = (player.y - *map_y * 64) * delta_dist_y;
//     } else {
//         *step_y = 1;
//         wall_dist = (*map_y * 64 + 64 - player.y) * delta_dist_y;
//     }
//     return wall_dist;
// }


// int get_intersection(Vec2 ray, int map[MAP_WIDTH][MAP_HEIGHT], int map_x, int map_y, int step_x, int step_y, double wall_dist, int distance, int *hit) {
//     if (wall_dist < distance) {
//         if (map[map_x][map_y] > 0)
//             *hit = 1;
//         if (ray.x < ray.y) {
//             map_x += step_x;
//             distance = wall_dist;
//             wall_dist += fabs(1 / ray.x);
//         } else {
//             map_y += step_y;
//             distance = wall_dist;
//             wall_dist += fabs(1 / ray.y);
//         }
//     }
//     return distance;
// }



// void ray_casting(t_game *game) {
//     for (int x = 0; x < WIDTH; x++) {
//         double ray_angle = (game->angle - game->fov / 2) + (game->fov * x / WIDTH);
//         Vec2 ray = get_ray(game->angle, ray_angle);
//         int map_x, map_y, step_x, step_y;
//         double wall_dist = get_wall_distance(ray, game->player, &map_x, &map_y, &step_x, &step_y);
//         int distance = 0;
//         int hit = 0;
//         while (!hit) {
//             distance = get_intersection(ray, game->map, map_x, map_y, step_x, step_y, wall_dist, distance, &hit);
//         }
//         render_column(game, x, distance);
//     }
// }



// void game_loop(t_game *game) {
//     int key_press = 0;
//     while (1) {
//         move_player(game);
//         ray_casting(game);
//         mlx_loop_hook(game->mlx, game_loop, game);
//         key_press = mlx_get_key(game->mlx, game->window);
//         if(key_press == 53) {
//           mlx_destroy_window(game->mlx, game->window);
//           exit(0);
//         }
//     }
// }



int	main(int argc, char **argv)
{

	t_game	*game;
	game = malloc(sizeof(t_game));
	init_struct(game);
	check_file_name(argc, argv[1], game);
	read_check_map(argv[1], game);
	print_data(game);
	
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cube3D");
    draw_minimap(game);
	init_game(game);
    mlx_key_hook(game->window, handle_key_press, game);
    mlx_loop(game->mlx);
	// Vec2 player = {game->p_x, game->p_y};
	// game->fov = M_PI / 3;
	// game->angle = 0;

    // game_loop(&game);
    return 0;
}