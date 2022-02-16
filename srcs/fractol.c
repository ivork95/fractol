/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 21:21:47 by ivork         #+#    #+#                 */
/*   Updated: 2022/02/16 16:31:47 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <complex_num.h>
#include <math.h>
#include <fractol.h>

unsigned int	julia_set(t_complex complex)
{
	t_complex	z;
	t_complex	constant;
	double		n;

	n = 0.0;
	z.imaginary = complex.imaginary;
	z.real = complex.real;
	constant.real = complex.constant->real;
	constant.imaginary = complex.constant->imaginary;
	while (absolute_complex(z) < 4 && (n < MAX_ITER))
	{
		z = multiply_complex_num(z, z);
		z = add_complex_num(z, constant);
		n++;
	}
	return (n);
}

unsigned int	mandelbrot_set(t_complex complex)
{
	t_complex	z;
	double		n;

	n = 0.0;
	z.imaginary = 0;
	z.real = 0;
	while (absolute_complex(z) < 4 && (n < MAX_ITER))
	{
		z = multiply_complex_num(z, z);
		z = add_complex_num(z, complex);
		n++;
	}
	return (n);
}
