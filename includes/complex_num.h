/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   complex.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 14:21:18 by ivork         #+#    #+#                 */
/*   Updated: 2021/11/09 14:21:18 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_complex
{
	float	real;
	float	imaginary;
}	t_complex;

t_complex	multiply_complex_num(t_complex num1, t_complex num2);
t_complex	add_complex_num(t_complex num1, t_complex num2);
