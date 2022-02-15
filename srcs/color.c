/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 18:03:45 by ivork         #+#    #+#                 */
/*   Updated: 2022/02/15 19:27:26 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	get_rgb(int n)
{
	int		r;
	int		g;
	int		b;
	float	t;
	
	if (n == MAX_ITER)
		return (0);
	t = (float)n / (float)MAX_ITER;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) + (g << 8) + b);
}
