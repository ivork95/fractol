/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/25 11:19:32 by ivork         #+#    #+#                 */
/*   Updated: 2022/03/02 14:18:10 by ivork         ########   odam.nl         */
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
	float			y_move;
	float			x_move;
	unsigned int	(*set)(t_complex, t_complex);
	t_complex		*constant;
}					t_vars;

void		create_window(t_vars *vars, char **info);
void		error_func(void);
int			scale_frame(int key_code, int x, int y, t_vars *vars);
int			close_window(t_vars *vars);
int			key_press(int key_code, t_vars *vars);
int			plot_frame(t_vars *vars);

#endif
