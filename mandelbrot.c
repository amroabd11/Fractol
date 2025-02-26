/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:28:49 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/26 12:13:01 by aamraouy         ###   ########.fr       */
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
	while (z.z_re * z.z_re + z.z_im * z.z_im <= 4 && iter++ < 100)//this loop iteration is about checking wither we get out the mandel set or not ,by checking the iter value 
	{
		z_new_re = z.z_re * z.z_re - z.z_im * z.z_im + c.c_re;
		z.z_im = 2.0 * z.z_re * z.z_im + c.c_im;
		z.z_re = z_new_re;
	}
	if (iter == 100)
		fractus->image.color = 255;
	else
		fractus->image.color = (iter * 255) / 100;
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

	img = image_init(fractus);
	while (y < fractus->height)
	{
		c.c_im = fractus->max_im - (y * (fractus->max_im - fractus->min_im) / (HEIGHT - 1));//c coordinates in y-axis
		x = 0;
		while (x < fractus->width)
		{
			c.c_re = fractus->min_re + (x * (fractus->max_re - fractus->min_re) / (WIDTH - 1));
			z.z_re = 0;
			z.z_im = 0;
			// c.c_im = map_imag(y, fractus);
			// c.c_re = map_real(x, fractus);
			math_stuff(fractus, c, z, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractus->mlx_connect, fractus->mlx_window,
							img, 0, 0);
	mlx_destroy_image(fractus->mlx_connect, img);
}
