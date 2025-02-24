/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:51:10 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/24 16:32:09 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_fractal *fractus)
{
	double	zoom_factor;

	if (button == 4)
		zoom_factor = 0.9;
	else if (button == 5)
		zoom_factor = 1.1;
	else
		return (0);
	double mouse_re = fractus->min_re + x * (fractus->max_re - fractus->min_re) / (fractus->width - 1);
	double mouse_im = fractus->max_im - y * (fractus->max_im - fractus->min_im) / (fractus->height - 1);
	double new_width = (fractus->max_re - fractus->min_re) * zoom_factor;
	double new_height = (fractus->max_im - fractus->min_im) * zoom_factor;
	fractus->min_re = mouse_re - new_width / 2;
	fractus->max_re = mouse_re + new_width / 2;
	fractus->min_im = mouse_im - new_height / 2;
	fractus->max_im = mouse_im + new_height / 2;
	draw_mandelbrot(fractus, 0, 0);
	return (0);
}	
