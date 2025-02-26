/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:51:10 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/26 12:01:11 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int x, int y, t_fractal *f, double zoomfactor)
{
	double	width;
	double	hight;
	double	new_h;
	double	new_w;

	width = (f->max_re - f->min_re) * f->view.zoom;
	hight = (f->max_im - f->min_im) * f->view.zoom;
	new_w = (f->max_re - f->min_re) * (f->view.zoom * zoomfactor);
	new_h = (f->max_im - f->min_im) * (f->view.zoom * zoomfactor);
	f->view.zoom *= zoomfactor;
	f->view.offx -= ((double)x / WIDTH) * (new_w - width);
	f->view.offy -= ((double)y / HEIGHT) * (new_h - hight);
}

double map_real(int x, t_fractal *f)
{
	// f->view.offx = 0.0;
	return (f->min_re * f->view.zoom + f->view.offx + x * ((f->max_re - f->min_re) * f->view.zoom) / WIDTH);
}

double map_imag(int y, t_fractal *f)
{
	// f->view.offy = 0.0;
	return (f->max_im * f->view.zoom + f->view.offy - y * ((f->max_im - f->min_im) * f->view.zoom) / HEIGHT);
}

int	mouse_hook(int button, int x, int y, t_fractal *fractus)
{
	double	zoom_factor;

	if (button == 4)
		zoom_factor = 0.9;
	else if (button == 5)
		zoom_factor = 1.1;
	else
		return (0);
	// double mouse_re = fractus->min_re + x * (fractus->max_re - fractus->min_re) / (fractus->width - 1);
	// double mouse_im = fractus->max_im - y * (fractus->max_im - fractus->min_im) / (fractus->height - 1);
	// double new_width = (fractus->max_re - fractus->min_re) * zoom_factor;
	// double new_height = (fractus->max_im - fractus->min_im) * zoom_factor;
	// fractus->min_re = mouse_re - new_width / 2;
	// fractus->max_re = mouse_re + new_width / 2;
	// fractus->min_im = mouse_im - new_height / 2;
	// fractus->max_im = mouse_im + new_height / 2;
	zoom(x, y, fractus, zoom_factor);
	draw_mandelbrot(fractus, 0, 0);
	return (0);
}

int	event_handler(int keysym, t_fractal *fractus)
{
	if (keysym == 53)
	{
		mlx_destroy_window(fractus->mlx_connect, fractus->mlx_window);
		exit (0);
	}
	return (0);
}
