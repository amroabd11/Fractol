
#include "fractol.h"

void    fractal_init(t_fractal *fractal)
{
	fractal->mlx_connect = mlx_init();
	if (NULL == fractal->mlx_connect)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connect, WIDTH, HEIGHT, fractal->title);
	if (NULL == fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connect);
		free(fractal->mlx_connect);
		malloc_error();
	}

}
