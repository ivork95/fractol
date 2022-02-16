/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 21:16:59 by ivork         #+#    #+#                 */
/*   Updated: 2022/02/15 20:52:40 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>
#include <colors.h>
#include <fractol.h>
#include <../libft/libft.h>

#include <stdio.h>

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	plot_frame(t_vars *vars)
{
	t_complex		complex;
	unsigned int	color;
	int				x;
	int				y;

	x = 0;
	complex.constant = vars->constant;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			complex.real = (vars->max_x - vars->min_x) / WIDTH * (double)x
					- vars->x_offset;
			complex.imaginary = (vars->max_y - vars->min_y) / HEIGTH * (double)y
					- vars->y_offset;
			color = get_rgb(vars->set(complex));
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
	if (key_code == ZOOM_OUT)
	{
		plot_frame(vars);
	}
	if (key_code == ZOOM_IN)
	{
		plot_frame(vars);
	}
	return (key_code);
}

int	close_window(int key_code, t_vars *vars)
{
	if (key_code == UP)
		vars->y_offset += 0.1;
	else if (key_code == DOWN)
		vars->y_offset -= 0.1;
	else if (key_code == LEFT)
		vars->x_offset += 0.1;
	else if (key_code == RIGHT)
		vars->x_offset -= 0.1;
	else if (key_code == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else
		return (key_code);
	plot_frame(vars);
	return (key_code);
}

void	create_window(t_vars *vars, char **info)
{

	if (!ft_strncmp(info[1], "mandel", 7))
	{
		vars->set = &mandelbrot_set;
		vars->x_offset = 2.5 * scale;
	}
	else if (!ft_strncmp(info[1], "julia", 6))
	{
		if (info[2])
		vars->constant->real = ft_atod(info[2]);
		if (info[3])
			vars->constant->imaginary = ft_atod(info[3]);
		vars->set = &julia_set;
		vars->x_offset = 2;
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
