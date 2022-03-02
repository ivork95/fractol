/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 17:20:41 by ivork         #+#    #+#                 */
/*   Updated: 2022/03/02 14:48:11 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>
#include <stdlib.h>
#include <../libft/ft_printf/ft_printf.h>

void	error_func(void)
{
	ft_printf("Invalid input: Please run program with a parameter\n"
		"-mandelbrot\n-julia\n\n"
		"Run program for mandelbrot set as followed:\n"
		"./fractol mandelbrot\n\n"
		"For the Julia set add a constant e.g.:\n./fractol julia -0.7 0.27015\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars.constant = malloc(sizeof(t_complex));
	if (argc < 2)
		error_func();
	create_window(&vars, argv);
	plot_frame(&vars);
	mlx_key_hook(vars.win, key_press, &vars);
	mlx_mouse_hook(vars.win, scale_frame, &vars);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_loop(vars.mlx);
	free(vars.constant);
	return (0);
}
