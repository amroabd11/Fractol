/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:28:49 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/24 17:07:38 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	endian_zero(t_fractal *fractus, int pixel)
{
		fractus->image.buffer[pixel + 0] = fractus->image.color & 255;
		fractus->image.buffer[pixel + 1] = (fractus->image.color >> 8) & 255;
		fractus->image.buffer[pixel + 2] = (fractus->image.color >> 16) & 255;
		fractus->image.buffer[pixel + 3] = (fractus->image.color >> 24) & 255;
}

void	math_stuff(t_fractal *fractus, t_complex c, t_complex z, int x, int y)
{
	double	z_new_re;
	int		pixel;
	int		iter;

	iter = 0;
	z.z_re = c.c_re;
	z.z_im = c.c_im;
	while (z.z_re * z.z_re + z.z_im * z.z_im <= 4 && iter++ < 100)
	{
		z_new_re = z.z_re * z.z_re - z.z_im * z.z_im + c.c_re;
		z.z_im = 2.0 * z.z_re * z.z_im + c.c_im;
		z.z_re = z_new_re;
	}
	if (x == 100)
		fractus->image.color = 0b000000000000000000000000;
	else
		fractus->image.color = 0b000000001111111100000000;
	pixel = (y * fractus->image.line_bytes) + (x * 4);
	if (fractus->image.endian == 1)
	{
		fractus->image.buffer[pixel + 0] = (fractus->image.color >> 24) & 255;
		fractus->image.buffer[pixel + 1] = (fractus->image.color >> 16) & 255;
		fractus->image.buffer[pixel + 2] = (fractus->image.color >> 8) & 255;
		fractus->image.buffer[pixel + 3] = fractus->image.color & 255;
	}
	else
		endian_zero(fractus, pixel);
}

void	draw_mandelbrot(t_fractal *fractus, int x, int y)
{
	void	*img;
	t_complex	c;
	t_complex	z;

	img = mlx_new_image(fractus->mlx_connect, WIDTH, HEIGHT);
	fractus->image.buffer = mlx_get_data_addr(img,
												&fractus->image.bits_per_pexil,
												&fractus->image.line_bytes,
												&fractus->image.endian);
	while (y < fractus->height)
	{
		c.c_im = fractus->max_im - (y * (fractus->max_im - fractus->min_im) / (fractus->height - 1));//c coordinates in y-axis
		x = 0;
		while (x < fractus->width)
		{
			c.c_re = fractus->min_re + (x * (fractus->max_re - fractus->min_re) / (fractus->width - 1));
			math_stuff(fractus, c, z, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractus->mlx_connect, fractus->mlx_window,
							img, 0, 0);
	mlx_destroy_image(fractus->mlx_connect, img);
}
