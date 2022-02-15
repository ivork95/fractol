/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   complex.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 14:25:07 by ivork         #+#    #+#                 */
/*   Updated: 2022/02/09 16:48:14 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <complex_num.h>
#include <math.h>

t_complex	multiply_complex_num(t_complex num1, t_complex num2)
{
	t_complex	value;

	value.real = num1.real * num2.real - num1.imaginary * num2.imaginary;
	value.imaginary = num1.real * num2.imaginary + num1.imaginary * num2.real;
	return (value);
}

t_complex	add_complex_num(t_complex num1, t_complex num2)
{
	t_complex	value;

	value.real = num1.real + num2.real;
	value.imaginary = num1.imaginary + num2.imaginary;
	return (value);
}

float	absolute_complex(t_complex complex)
{
	float	x;

	x = complex.real * complex.real + complex.imaginary
			* complex.imaginary;
	return (x);
}
