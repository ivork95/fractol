# Fractol

## Overview

Fractol is a basic computer graphics project that focuses on rendering fractals.

## Usage

1. Clone the repository.
2. Compile the program using `make`.
3. Run the program with the following command:

./fractol [parameter]

- `parameter`: This defines what type of fractal will be displayed in the window.
  - For the Mandelbrot set: Don't provide any parameter.
  - For the Julia set: Provide two parameters separated by space, representing the real and imaginary parts of the constant 'c'.

### Example

To display the Mandelbrot set:
```bash
$ ./fractol
```

To display a Julia set with constant 'c' as -0.54 + 0.54i:
```bash
$ ./fractol -.0.54 0.54
```
