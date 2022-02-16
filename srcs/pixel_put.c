/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixel_put.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 16:26:32 by ivork         #+#    #+#                 */
/*   Updated: 2022/02/16 16:29:32 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
