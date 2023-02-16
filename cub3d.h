/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:05:27 by alalmazr          #+#    #+#             */
/*   Updated: 2023/02/16 13:54:26 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <unistd.h>
# include <pthread.h>
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

typedef struct s_data
{
	void				*img;
	void				*img_minimap;
	void				*win;
	void				*mlx;
	void				*ptr[4];
	unsigned int		*texture[4];
	int					bpp[4];
	int					ll[4];
	int					en[4];
	// int					door_open_bpp;
	// int					door_open_ll;
	// int					door_open_en;
	// int					door_close_bpp;
	// int					door_close_ll;
	// int					door_close_en;				
	// int					enemy0_bpp;
	// int					enemy0_ll;
	// int					enemy0_en;
	char				*first_line;
	char				*addr;
	double				pos_x;
	double				pos_y;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	char				**s;
	unsigned int		buffer[SCREENHEIGHT][SCREENWIDTH];
	int					width[4];
	int					height[4];
	// int					door_open_width;
	// int					door_open_height;
	// int					door_close_width;
	// int					door_close_height;
	// int					*door_open_texture;
	// int					*door_close_texture;
	// unsigned int		*enemy0_texture;
	// unsigned int		*enemy1_texture;
	// unsigned int		*enemy2_texture;
	// int					enemy0_width;
	// int					enemy0_height;
	char				**data;
	char				**map;
	unsigned int		drawstart;
	unsigned int		drawend;
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
	char				*ea;
	char				*so;
	char				*we;
	char				*no;
	t_ccolor			c_color;
	t_fcolor			f_color;
	// void				*door_open_ptr;
	// void				*door_close_ptr;
	// void				*enemy0_prt;
	// void				*enemy1_prt;
	// void				*enemy2_prt;
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
	// float				walkspeed;
	// int					music_pid;
	void				*bag_map;
	void				*add_bag_map;
}	t_data;

typedef struct s_loc
{
	unsigned int	y;
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			perpwalldist;
	double			wall_x;
	double			step;
	double			texpos;
	int				x;
	int				map_x;
	int				map_y;
	int				lineheight;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				tex_x;
	int				tex_y;
	int				color;
}					t_loc;

int		fill_data(t_data *game);
int		check(char **data);
int		start_one(char *str);
void	raycast(t_data *game);
int		key_event(int keycode, t_data *game);
int		arr_2d_len(void **arr);
void	print_arr(char **arr);
t_list	*arr_2_list(char **arr);
void	free_arr(void **arr);
char	**lst_2_arr(t_list *list);
void	read_map(char *str, t_data *game);
void	draw_player(t_data *game);
int		first_space(char **line);
void	draw_map( t_data *game);
void	draw_line(t_data *game);
void	my_mlx_pixel_put(t_data *game, int x, int y, int color);
int		f_lline(t_data *game);
void	minimap_walls(t_data *game, int x, int y, int color);
void	my_mlx_pixel_put1(t_data *game, int x, int y, int color);
void	minimap(t_data *game);
char	**rotate_arr(char **arr);
char	**rotate_arr(char **arr);
void	key_check_rotate(int keycode, t_data *game);
int		ft_max(int a, int b);
void	ft_error(void);
void	print_arr(char **arr);
void	print_list(t_list *list);
t_list	*arr_2_list(char **arr);
char	**lst_2_arr(t_list *list);
char	**cpy_arr(char **arr);
char	*listtostr(t_list *arr);
char	*arrtostr(char **arr);
int		arr_2d_len(void **arr);
int		check_color_range(t_data *game);
int		color_fill(t_data *game);
int		exist_image(t_data *game);
int		check_img(char *str);
int		check_all_imgs(t_data *game);
int		invalid_img(char *str);
char	**ft_remove_new_line(char **arr);
int		invalid_map(char **map);
int		check_zeros(t_data *game);
int		check_p_pos(char **map);
int		check_close_map(char **map);
int		make_color(int t, int r, int g, int b);
void	my_mlx_pixel_put_alpha(t_data *game, int x, int y, int color);
int		check_err(t_data *game);
void	init(t_data *game);
void	set_pos(t_data *game);
int		check_char(char c);
int		check_color1(t_data *game, int *k, int *i);
void	check_color2(t_data *game, int *n, int *j);
void	check_color3(t_data *game, int *n, int *j);
char	*ft_strcpy(char *dest, char const *src);
void	create_img1(t_data *game);
void	create_img2(t_data *game);
void	create_img3(t_data *game);
int		mouse(int x, int y, t_data *game);
void	draw_player_helper(t_data *game, int i, int j, int skip);
int		frame_conter(void *data);//
int		mouse_hook(int keycode, int x, int y, t_data *game);
void	move_up(t_data *game, double nextp_x, double nextp_y, int skip);
void	move_down(t_data *game, double nextp_x, double nextp_y, int skip);
void	key_check_updown(int keycode, t_data *game);
char	*read_first_line(int fd);
char	*remove_empty_lines(char *line, int fd);
t_list	*get_lines(int fd, t_data *game);
void	make_map(t_list *list, t_data *game);
void	read_map(char *str, t_data *game);
int		open_file(char *str);
char	*read_meta_data(int fd, t_data *game, char *line);
void	move_down(t_data *game, double nextp_x, double nextp_y, int skip);
void	check_name(char *str);
int		get_t(int trgb);
void	raycast_help1(t_data *game, t_loc *loc);
void	raycast_help2(t_data *game, t_loc *loc);
void	raycast_help3(t_data *game, t_loc *loc);
void	raycast_help4(t_data *game, t_loc *loc);
void	raycast_help5(t_data *game, t_loc *loc);
void	raycast_help6(t_data *game, t_loc *loc);
void	init_loc(t_loc *loc, int x, int mapx, int mapy);
void	raycast_help(t_data *game, int x, int mapx, int mapy);
void	put_imgs(t_data *game);
void	raycast(t_data *game);
void	raycast_framing(t_data *game, t_loc *loc);
void	raycast_f(t_data *game, t_loc *loc, int i);
void	raycast_help5(t_data *game, t_loc *loc);
void	white_box1(t_data *game, int x, int y, int color);
void	change_speed(int keycode, t_data *game);
void	white_box2(t_data *game, int x, int y, int color);
void	draw_big_map(t_data *game);
void	my_mlx_pixel_put3(t_data *game, int x, int y, int color);
#endif