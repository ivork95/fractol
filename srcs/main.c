/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 17:20:41 by ivork         #+#    #+#                 */
/*   Updated: 2022/02/09 17:20:51 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <window.h>
#include <stdlib.h>

void	error_func(void)
{
	printf("Invalid input: Please run program with a parameter\n"
		"-mandel\n-julia\n\n"
		"Run program for mandelbrot set as followed:\n"
		"./fractol mandelbrot\n\n"
		"For the Julia set add a constant e.g.:\n./fractol julia -0.7 0.27015\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc < 2)
		error_func();
	create_window(&vars, argv);
	plot_frame(&vars);
	mlx_key_hook(vars.win, close_window, &vars);
	mlx_mouse_hook(vars.win, scale_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
