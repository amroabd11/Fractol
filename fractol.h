/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:05:44 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/27 09:22:43 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "minilibx/mlx.h"
# define WIDTH 800
# define HEIGHT 800

typedef struct s_fractal
{
	void    *mlx_connect;
	void    *mlx_window;
	void    *img;
	char    *buffer;
	int     bpp;
	int     line_bytes;
	int     endian;
	double  zoom;
	double  x_offset;
	double  y_offset;
}	t_fractal;

int		event_handler(int keysym, t_fractal *fractus);
void	*image_init(t_fractal *fractus);
void	establish_connection(t_fractal *fractus);
void	draw_mandelbrot(t_fractal *fractus);
int		mouse_hook(int button, int x, int y, t_fractal *fractus);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char *str);
void	error_exit(char *error);

#endif