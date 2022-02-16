/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 21:27:48 by ivork         #+#    #+#                 */
/*   Updated: 2022/02/16 15:52:33 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MAX_ITER 100
# include <complex_num.h>

unsigned int	julia_set(t_complex complex);
unsigned int	mandelbrot_set(t_complex complex);
#endif
