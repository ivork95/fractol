/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   complex_num.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 14:21:18 by ivork         #+#    #+#                 */
/*   Updated: 2022/02/09 16:06:03 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_NUM_H
# define COMPLEX_NUM_H 

typedef struct s_complex
{
	float				real;
	float				imaginary;
	struct s_complex	*constant;
}	t_complex;

t_complex	multiply_complex_num(t_complex num1, t_complex num2);
t_complex	add_complex_num(t_complex num1, t_complex num2);
float		absolute_complex(t_complex complex);

#endif
