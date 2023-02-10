/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlils6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:07:45 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/10 08:41:16 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	frame_counter(void *data)
{
	t_data	*img;

	img = (t_data *)data;
	img->frame++;
	raycast(img);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *img)
{
	(void)x;
	(void)y;
	(void)img;
	if (keycode == 1)
		mlx_put_image_to_window(img->mlx, img->win, img->gun2, 450, 510);
	return (0);
}
