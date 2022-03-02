/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 21:16:59 by ivork         #+#    #+#                 */
/*   Updated: 2022/03/02 14:28:59 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>
#include <colors.h>
#include <fractol.h>
#include <../libft/libft.h>
#include <pixel_put.h>

int	plot_frame(t_vars *vars)
{
	t_complex		complex;
	unsigned int	color;
	int				x;
	int				y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			complex.real = (vars->scale * 3.0 / WIDTH * (double)x
					- vars->scale * vars->x_offset) - vars->x_move;
			complex.imaginary = (vars->scale * 3.0 / HEIGTH * (double)y
					- vars->scale * vars->y_offset) - vars->y_move;
			color = get_rgb(vars->set(complex, *vars->constant));
			my_mlx_pixel_put(&vars->img, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (1);
}

int	scale_frame(int key_code, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (key_code == ZOOM_OUT)
	{
		vars->scale *= 1.05;
		plot_frame(vars);
	}
	if (key_code == ZOOM_IN)
	{
		vars->scale *= 0.95;
		plot_frame(vars);
	}
	return (key_code);
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_press(int key_code, t_vars *vars)
{
	if (key_code == UP)
		vars->y_move += 0.1 * vars->scale;
	else if (key_code == DOWN)
		vars->y_move -= 0.1 * vars->scale;
	else if (key_code == LEFT)
		vars->x_move += 0.1 * vars->scale;
	else if (key_code == RIGHT)
		vars->x_move -= 0.1 * vars->scale;
	else if (key_code == ESC)
		close_window(vars);
	else
		return (key_code);
	plot_frame(vars);
	return (key_code);
}

void	create_window(t_vars *vars, char **info)
{
	vars->x_move = 0;
	vars->y_move = 0;
	vars->y_offset = 1.5;
	if (!ft_strncmp(info[1], "mandelbrot", 7))
	{
		vars->set = &mandelbrot_set;
		vars->x_offset = 2;
	}
	else if (!ft_strncmp(info[1], "julia", 6))
	{
		if (info[2])
			vars->constant->real = ft_atod(info[2]);
		if (info[3])
			vars->constant->imaginary = ft_atod(info[3]);
		vars->set = &julia_set;
		vars->x_offset = 1.5;
	}
	else
		error_func();
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGTH, "Fractol");
	vars->img.img = mlx_new_image(vars->mlx, WIDTH, HEIGTH);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	vars->scale = 1;
}
