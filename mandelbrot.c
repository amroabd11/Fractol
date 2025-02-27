/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:28:49 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/27 09:19:22 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_tobuffer(t_fractal *fractus, int x, int y, int color)
{
	char *dst;

	dst = fractus->buffer + (y * fractus->line_bytes + x * (fractus->bpp / 8));
	*(unsigned int*)dst = color;
}

int	math_stuff(double c_re, double c_im)
{
	double	z_new_re;
	int		iter;
	int		color;
	double	z_re;
	double	z_im;

	iter = 0;
	z_re = 0;
	z_im = 0;
	while (z_re * z_re + z_im * z_im <= 4 && iter++ < 100)
	{
		z_new_re = z_re * z_re - z_im * z_im + c_re;
		z_im = 2.0 * z_re * z_im + c_im;
		z_re = z_new_re;
	}
	if (iter == 100)
		return (0xFFFFFF);
	color = (iter * 255 / 100);
	return ((color << 16) | (color << 8) | color);
}

void	draw_mandelbrot(t_fractal *fractus)
{
	void	*img;
	int		color;
	double	c_im;
	double	c_re;
	int			x;
	int			y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c_im = y / fractus->zoom + fractus->y_offset;
			c_re = x / fractus->zoom + fractus->x_offset;
			color = math_stuff(c_re, c_im);
			put_pixel_tobuffer(fractus, x, y, color);
			x++;
		}
		y++;
	}
}
