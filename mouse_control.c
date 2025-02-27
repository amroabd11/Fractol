/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:51:10 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/27 09:24:03 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_fractal *fractus)
{
	double	mouse_re;
	double	mouse_im;

    if (button == 4 || button == 5)
    {
        // Calculate the complex coordinate corresponding to the mouse position
        mouse_re = x / fractus->zoom + fractus->x_offset;
        mouse_im = y / fractus->zoom + fractus->y_offset;
        if (button == 5) // Zoom in
            fractus->zoom *= 1.1;
        else if (button == 4) // Zoom out
            fractus->zoom *= 0.9;
        // Adjust offsets so that the point under the cursor remains fixed
        fractus->x_offset = mouse_re - x / fractus->zoom;
        fractus->y_offset = mouse_im - y / fractus->zoom;
        // Recreate the image and redraw the fractal
        mlx_destroy_image(fractus->mlx_connect, fractus->img);
        fractus->img = mlx_new_image(fractus->mlx_connect, 800, 800);
        fractus->buffer = mlx_get_data_addr(fractus->img, &fractus->bpp,
                                        &fractus->line_bytes, &fractus->endian);
        draw_mandelbrot(fractus);
        mlx_put_image_to_window(fractus->mlx_connect, fractus->mlx_window, fractus->img, 0, 0);
    }
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
