#include "includes/complex_num.h"
#include <stdio.h>
#include <math.h>

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
	while (absolute_complex(z) < 2 && (n < 1000))
	{
		z = multiply_complex_num(z, z);
		z = add_complex_num(z, complex);
		n++;
	}
	if (n == 1000)
	{
		printf("black pixel\n");
		return (0);
	}
	else
		return (0x00FF0000);
}
int main(void)
{
	t_complex complex;

	complex.real = 0;
	complex.imaginary = 0;
	printf("%d\n", mandelbrot_set(complex));
}

