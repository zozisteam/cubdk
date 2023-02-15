/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:57:55 by mraspors          #+#    #+#             */
/*   Updated: 2023/02/15 22:47:53 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <unistd.h>
# include <signal.h>

# define MAPWIDTH 24
# define MAPHEIGHT 24
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define SCREENWIDTH 1800
# define SCREENHEIGHT 960
# define ROTSPEED 0.1
# define WALKSPEED 0.185

typedef struct f_color
{
	char	*f;
	int		r;
	int		g;
	int		b;
}		t_fcolor;

typedef struct c_color
{
	char	*c;
	int		r;
	int		g;
	int		b;
}t_ccolor;

typedef struct s_game
{
	void				*game;
	void				*img_minimap;
	void				*win;
	void				*mlx;
	void				*ptr[4];
	unsigned int		*texture[4];
	int					bpp[4];
	int					ll[4];
	int					en[4];
	char				*first_line;
	char				*addr;
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	char				**s;
	unsigned int		buffer[SCREENHEIGHT][SCREENWIDTH];
	int					width[4];
	int					height[4];
	char				**data;
	char				**map;
	unsigned int		draw_start;
	unsigned int		draw_end;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					bpp_line;
	int					size_line;
	void				*minimap_addr;
	void				*img_alpha;
	void				*addr_alpha;
	float				posx;
	float				posy;
	float				player_dir;
	char				*_ea;
	char				*_so;
	char				*_we;
	char				*_no;
	t_ccolor			c_color;
	t_fcolor			f_color;
	unsigned long long	frame;
	void				*gun1;
	void				*gun2;
	void				*aim;
	int					size;
	float				var1;
	float				var2;
	float				var3;
	float				var4;
	float				dx;
	float				dy;
	int					map_x;
	int					map_y;
	double				camera_x;
	double				raydir_x;
	double				raydir_y;
	double				sidedist_x;
	double				sidedist_y;
	double				deltadist_x;
	double				deltadist_y;
	double				perpwalldist;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	int					lineheight;
	double				wall_x;
	int					tex_x;
	int					tex_y;
	double				step;
	double				tex_pos;
	unsigned int		color;
	unsigned int		i;
	unsigned int		y;
	int					max_size;
	int					with;
	int					skip;
	int					x;
	char				*read_data_line;
	char				*read_data_tmp;
	double				olddir;
	double				oldplane;
}				t_game;

int		fill_data(t_game *game);
int		check(char **game);
int		start_one(char *str);
void	raycast(t_game *game);
int		key_event(int keycode, t_game *game);
int		arr_2d_len(void **arr);
void	printarr(char **arr);
t_list	*ft_arrtolst(char **arr);
void	ft_freearray(void **arr);
char	**ft_lsttoarr(t_list *list);
void	read_map(char *str, t_game *game);
void	draw_player(t_game *data);
int		first_space(char **line);
void	draw_map( t_game *data);
void	draw_line(t_game *data);
int		max_line_len(t_game *data);
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
void	my_mlx_pixel_put1(t_game *data, int x, int y, int color);
void	minimap(t_game *data);
char	**rotate_arr(char **arr);
void	key_rotate_event(int keycode, t_game *game);
int		max_(int a, int b);
void	error_(void);
void	printarr(char **arr);
void	printlist(t_list *list);
t_list	*ft_arrtolst(char **arr);
char	**ft_lsttoarr(t_list *list);
char	**cpy_arr(char **arr);
char	*listtostr(t_list *arr);
char	*arrtostr(char **arr);
int		arr_2d_len(void **arr);
int		check_color_range(t_game *data);
int		fill_color(t_game *data);
int		exist_image(t_game *data);
int		check_img_exist(char *str);
int		chek_imgs(t_game *data);
int		invalid_img(char *str);
char	**ft_remove_new_line(char **arr);
int		invalid_map(char **map);
int		check_zeros(t_game *data);
int		check_dir(char **map);
int		check_close_map(char **map);
int		make_color(int t, int r, int g, int b);
int		check_error(t_game *img);
void	init(t_game	*img);
void	set_pos(t_game *game);
int		check_char(char c);
int		check_color(t_game *data, int *k, int *i);
void	check_color2(t_game *data, int *n, int *j);
void	check_color3(t_game *data, int *n, int *j);
char	*ft_strcpy(char *dest, char const *src);
void	create_img1(t_game *game);
void	create_img2(t_game *game);
int		mouse(int x, int y, t_game *game);
void	draw_player_helper(t_game *data, int i, int j, int skip);
int		frame_counter(void *data);
void	key_check_updown(int keycode, t_game *game);
char	*read_first_line(int fd);
char	*remove_empty_lines(char *line, int fd);
t_list	*get_lines(int fd, t_game *data);
void	make_map(t_list *list, t_game *data);
int		open_file(char *str);
char	*get_file_data(int fd, t_game *data);
void	minimap_player(t_game *game, int x, int y, int color);
void	minimap_walls(t_game *game, int x, int y, int color);
void	move_up(t_game *game, double nextp_x, double nextp_y, int skip);
void	move_down(t_game *game, double nextp_x, double nextp_y, int skip);
void	raycast_init(t_game *game);
void	raycast_1(t_game *game);
void	raycast_2(t_game *game);
void	raycast_3(t_game *game);
void	raycast_4(t_game *game);
void	raycast_5(t_game *game);
void	raycast_5_helper(t_game *game);
void	raycast_6(t_game *game);
void	raycast_7(t_game *game);
void	raycast_8(t_game *game);
int		get_t(int trgb);
#endif