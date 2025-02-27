/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection_stuff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 08:13:01 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/27 09:07:59 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	establish_connection(t_fractal *fractus)
{
	fractus->mlx_connect = mlx_init();
	if (!fractus->mlx_connect)
	{
		perror("mlx_init");
		exit(1);
	}
	fractus->mlx_window = mlx_new_window(fractus->mlx_connect, 800, 800,
										"Mandelbrot Fractal");
	if (!fractus->mlx_window)
	{
		mlx_destroy_window(fractus->mlx_connect, fractus->mlx_window);
		error_exit("window");
	}
}

void	*image_init(t_fractal *fractus)
{
	void	*img;

	img = mlx_new_image(fractus->mlx_connect, WIDTH, HEIGHT);
	fractus->buffer = mlx_get_data_addr(img,
											&fractus->bpp,
											&fractus->line_bytes,
											&fractus->endian);
	return (img);
}
