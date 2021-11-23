#include <mlx.h>
#include <complex_num.h>
#include <stdio.h>
#include <math.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

long long absolute_complex(t_complex complex)
{
	double x;

	x = sqrt(complex.real * complex.real + complex.imaginary * complex.imaginary);
	return (x);
}
 
unsigned int mandelbrot_set(t_complex complex)
{
	t_complex z;
	int n;

	n = 0;
	z.imaginary = 0;
	z.real = 0;
	while (absolute_complex(z) < 2 && (n < 100))
	{
		z = multiply_complex_num(z, z);
		z = add_complex_num(z, complex);
		n++;
	}
	if (n == 100)
	{
		printf("black pixel\n");
		return (0);
	}
	else
		return (0x00FFFFF - n * n );
}

void plot_frame(t_data img, float scale, void *mlx, void *mlx_win)
{	
	t_complex complex;
	int x;
	int y;
	unsigned int color;

	x = 0;
	y = 0;
	while (x < 200)
	{
		y = 0;
		while (y < 100)
		{
			complex.real = (scale * 4.0/200.0 * (double)x - scale * 2.0) -0.75;
			complex.imaginary = (scale * 2.0/100.0 * (double)y - scale * 1.0) +0.1;
			color = mandelbrot_set(complex);
			my_mlx_pixel_put(&img, x, y, color);
			printf("x = %f\ny = %f\n", complex.real, complex.imaginary);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	float	scale;

	mlx = mlx_init();
	if (mlx != 0)
	mlx_win = mlx_new_window(mlx, 200, 100, "Hello world!");
	img.img = mlx_new_image(mlx, 200, 100);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	scale = 1;
	while (scale > 0.0005)
	{
		plot_frame(img, scale, mlx, mlx_win);
		scale *= 0.9;
	}

	mlx_loop(mlx);
	// complex.real = 2;
	// complex.imaginary = 2;
	// printf("%d\n", mandelbrot_set(complex));
}