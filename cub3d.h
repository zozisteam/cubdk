/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:57:55 by mraspors          #+#    #+#             */
/*   Updated: 2023/02/16 21:19:45 by mraspors         ###   ########.fr       */
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
}				t_data;

int		fill_data(t_data *data);
int		check(char **data);
int		start_one(char *str);
void	raycast(t_data *img);
int		key_check(int keycode, t_data *img);
int		arr_2d_len(void **arr);
void	printarr(char **arr);
t_list	*ft_arrtolst(char **arr);
void	ft_freearray(void **arr);
char	**ft_lsttoarr(t_list *list);
void	read_map(char *str, t_data *data);
void	draw_player(t_data *data);
int		first_space(char **line);
void	draw_map( t_data *data);
void	draw_line(t_data *data);
int		max_line_len(t_data *data);
void	my_mlx_pixel_put(t_data *game, int x, int y, int color);
void	my_mlx_pixel_put1(t_data *data, int x, int y, int color);
void	minimap(t_data *data);
char	**roted_arr(char **arr);
char	**roted_array(char **arr);
void	key_check_rotate(int keycode, t_data *img);
int		ft_max(int a, int b);
void	save_dir(t_data *data);
void	ft_error(void);
void	printarr(char **arr);
void	printlist(t_list *list);
t_list	*ft_arrtolst(char **arr);
char	**ft_lsttoarr(t_list *list);
char	**ft_copyarr(char **arr);
char	*listtostr(t_list *arr);
char	*arrtostr(char **arr);
int		arr_2d_len(void **arr);
int		check_color_range(t_data *data);
int		fill_color(t_data *data);
int		exist_image(t_data *data);
int		check_img_exist(char *str);
int		chek_imgs(t_data *data);
int		invalid_img(char *str);
char	**ft_remove_new_line(char **arr);
int		invalid_map(char **map);
int		check_whitespaces_in_map(t_data *data);
int		check_zeros(t_data *data);
int		cheack_if_dirc(char **map);
int		check_close_map(char **map);
int		make_color(int t, int r, int g, int b);
int		check_error(t_data *img);
void	init(t_data	*img);
void	set_pos(t_data *img);
int		check_char(char c);
int		check_color(t_data *data, int *k, int *i);
void	check_color2(t_data *data, int *n, int *j);
void	check_color3(t_data *data, int *n, int *j);
char	*ft_strcpy(char *dest, char const *src);
void	creat_imgs(t_data *img);
void	creat_imgs2(t_data *img);
int		mouse(int x, int y, t_data *img);
void	draw_player_helper(t_data *data, int i, int j, int skip);
int		frame_counter(void *data);
void	key_check_updown(int keycode, t_data *img);
char	*read_first_line(int fd);
char	*remove_empty_lines(char *line, int fd);
t_list	*get_lines(int fd, t_data *data);
void	make_map(t_list *list, t_data *data);
void	read_map(char *str, t_data *data);
int		open_file(char *str);
char	*read_meta_data(int fd, t_data *data);
void	minimap_player(t_data *game, int x, int y, int color);
void	minimap_walls(t_data *game, int x, int y, int color);
void	move_up(t_data *img, double nextp_x, double nextp_y, int skip);
void	move_down(t_data *img, double nextp_x, double nextp_y, int skip);
void	raycast_init(t_data *img);
void	raycast_1(t_data *img);
void	raycast_2(t_data *img);
void	raycast_3(t_data *img);
void	raycast_4(t_data *img);
void	raycast_5(t_data *img);
void	raycast_5_helper(t_data *img);
void	raycast_6(t_data *img);
void	raycast_7(t_data *img);
void	raycast_8(t_data *img);
int		get_t(int trgb);
#endif