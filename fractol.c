/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:05:50 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/27 09:22:10 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	julia(t_fractal *fractus, char *real, char *i)
// {
// 	void	*img;

// 	fractus->width = WIDTH;
// 	fractus->height = HEIGHT;
// 	fractus->mlx_connect = mlx_init();
// 	if (!fractus->mlx_connect)
// 	{
// 		perror("mlx_init");
// 		return ;
// 	}
// 	fractus->mlx_window = mlx_new_window(fractus->mlx_connect,
// 										fractus->width,
// 										fractus->height, "fractol");
// 	if (!fractus->mlx_window)
// 	{
// 		mlx_destroy_window(fractus->mlx_connect, fractus->mlx_window);
// 		error_exit("julia window error");
// 	}
// 	img = mlx_new_image(fractus->mlx_connect, WIDTH, HEIGHT);
// 	fractus->image.buffer = mlx_get_data_addr(img, &fractus->image.bits_per_pexil,
// 											&fractus->image.line_bytes,
// 											&fractus->image.endian);
// 	mlx_put_image_to_window(fractus->mlx_connect, fractus->mlx_window, img, 0, 0);
// 	mlx_loop(fractus->mlx_connect);
// 	exit(0);
// }

void	mandela(t_fractal *fractus)
{
	establish_connection(fractus);
	fractus->img = image_init(fractus);
	fractus->zoom = 200;
	fractus->x_offset = -2.0;
	fractus->y_offset = -1.5;
	draw_mandelbrot(fractus);
	mlx_put_image_to_window(fractus->mlx_connect, fractus->mlx_window,
							fractus->img, 0, 0);
	mlx_key_hook(fractus->mlx_window, event_handler, fractus);
	mlx_mouse_hook(fractus->mlx_window, mouse_hook, fractus);
	mlx_loop(fractus->mlx_connect);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractus;

	fractus = (t_fractal *)malloc(sizeof(t_fractal));
	if (!fractus)
	{
		perror("malloc failed ");
		exit(1);
	}
	// if ((argc == 4) && (ft_strncmp(argv[1], "julia", 5)) == 0)
		// julia(fractus, argv[2], argv[3]);
	if ((argc == 2) && (ft_strncmp(argv[1], "mandel", 6) == 0))
		mandela(fractus);
	else
	{
		ft_putstr_fd("./fractol mandel /OR/ ./fractol julia n1 n2\n", 0);
	}
	exit(1);
}
