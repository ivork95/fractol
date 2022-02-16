/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/25 11:19:32 by ivork         #+#    #+#                 */
/*   Updated: 2022/02/15 19:33:20 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <mlx.h>
# include <complex_num.h>

# define ESC 53
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define ZOOM_IN 5
# define ZOOM_OUT 4
# define WIDTH 800
# define HEIGTH 800
# define MIN_X -2
# define MAX_X 2
# define MIN_Y -2
# define MAX_X 2

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars {
	void			*mlx;
	void			*win;
	t_data			img;
	float			scale;
	float			x_offset;
	float			y_offset;
	unsigned int	(*set)(t_complex);
	t_complex		*constant;
}					t_vars;

void		create_window(t_vars *vars, char **info);
void		error_func(void);
int			scale_frame(int key_code, int x, int y, t_vars *vars);
int			close_window(int key_code, t_vars *vars);
int			plot_frame(t_vars *vars);
#endif
