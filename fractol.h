/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:05:44 by aamraouy          #+#    #+#             */
/*   Updated: 2025/02/25 08:45:58 by aamraouy         ###   ########.fr       */
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
// # define min_re -2.5
// # define min_im -1.0
// # define max_re 1.0
// # define max_im 1.0

typedef struct s_complex
{
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
}	t_complex;

typedef struct s_image
{
	void	*img_ptr;
	int		line_bytes;
	int		bits_per_pexil;
	int		endian;
	char	*buffer;
	int		color;
}	t_image;

typedef struct s_fractal
{
	int			width;
	double		min_re;
	double		min_im;
	double		max_re;
	double		max_im;
	int			height;
	void		*mlx_connect;
	void		*mlx_window;
	char		*title;
	t_image		image;
}	t_fractal;

void	*image_init(t_fractal *fractus);
void	establish_connection(t_fractal *fractus);
void	draw_mandelbrot(t_fractal *fractus, int x, int y);
int		mouse_hook(int button, int x, int y, t_fractal *fractus);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char *str);
void	error_exit(char *error);

#endif