/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:08:32 by sreinhol          #+#    #+#             */
/*   Updated: 2022/06/11 22:33:02 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	make_fractol(t_fractol *frctl)
{
	size_t	x;
	size_t	y;

	frctl->scale.real = (frctl->x_max - frctl->x_min) / WIDTH;
	frctl->scale.imag = (frctl->y_max - frctl->y_min) / HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		frctl->c.imag = frctl->y_max - y * frctl->scale.imag;
		x = 0;
		while (x < WIDTH)
		{
			frctl->c.real = frctl->x_min + x * frctl->scale.real;
			select_fractol(frctl, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(frctl->mlx_ptr, frctl->win_ptr,
		frctl->mlx_img, 0, 0);
	return (0);
}

void	select_fractol(t_fractol *frctl, size_t x, size_t y)
{
	if (frctl->frctl_type == MANDELBROT)
		mandelbrot_func(frctl, x, y);
	if (frctl->frctl_type == JULIA)
		julia_func(frctl, x, y);
	if (frctl->frctl_type == BURNING_SHIP)
		burning_ship_func(frctl, x, y);
}

void	julia_func(t_fractol *frctl, size_t width, size_t height)
{
	t_complex	z;
	t_complex	temp;
	int			maxiter;

	z.real = frctl->c.real;
	z.imag = frctl->c.imag;
	temp.real = z.real * z.real;
	temp.imag = z.imag * z.imag;
	maxiter = 100;
	frctl->counter = 0;
	while (temp.real + temp.imag <= 4 && frctl->counter < maxiter)
	{
		z.imag = 2 * z.real * z.imag + frctl->julia.imag;
		z.real = temp.real - temp.imag + frctl->julia.real;
		temp.real = z.real * z.real;
		temp.imag = z.imag * z.imag;
		frctl->counter++;
	}
	if (frctl->counter > 99)
		my_mlx_pixel_put(frctl, width, height, 0x00FFFFFF);
	else
		my_mlx_pixel_put(frctl, width, height,
			mlx_get_color_value(frctl,
				(frctl->counter * frctl->counter * 9 * frctl->colour_right)));
}

void	mandelbrot_func(t_fractol *frctl, size_t width, size_t height)
{
	t_complex	z;
	t_complex	temp;
	int			maxiter;

	z.real = frctl->c.real;
	z.imag = frctl->c.imag;
	temp.real = z.real * z.real;
	temp.imag = z.imag * z.imag;
	maxiter = 20;
	frctl->counter = 0;
	while (frctl->counter < maxiter)
	{
		z.imag = 2 * z.real * z.imag + frctl->c.imag;
		z.real = temp.real - temp.imag + frctl->c.real;
		temp.real = z.real * z.real;
		temp.imag = z.imag * z.imag;
		frctl->counter++;
		if (temp.real + temp.imag > 4)
			break ;
	}
	if (frctl->counter > 19)
		my_mlx_pixel_put(frctl, width, height, 0x00FFFFFF);
	else
		my_mlx_pixel_put(frctl, width, height, mlx_get_color_value(frctl,
				frctl->counter * 8 * 8 * frctl->colour_right));
}

void	burning_ship_func(t_fractol *frctl, size_t width, size_t height)
{
	t_complex	z;
	t_complex	temp;
	int			maxiter;

	z.real = frctl->c.real;
	z.imag = frctl->c.imag;
	temp.real = z.real * z.real;
	temp.imag = z.imag * z.imag;
	maxiter = 400;
	frctl->counter = 0;
	while (frctl->counter < maxiter)
	{
		z.imag = -2 * fabs(z.real * z.imag) + frctl->c.imag;
		z.real = temp.real - temp.imag + frctl->c.real;
		temp.real = z.real * z.real;
		temp.imag = z.imag * z.imag;
		frctl->counter++;
		if (temp.real + temp.imag > 4)
			break ;
	}
	if (frctl->counter > 19)
		my_mlx_pixel_put(frctl, width, height, 0x00FFFFFF);
	else
		my_mlx_pixel_put(frctl, width, height, mlx_get_color_value(frctl,
				 (frctl->counter * 8 * 8.5 * frctl->colour_right)));
}
