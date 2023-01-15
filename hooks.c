/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:08:40 by sreinhol          #+#    #+#             */
/*   Updated: 2022/01/17 16:14:54 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_fractol *frctl)
{
	if (keycode == ESC_KEY)
		exit(EXIT_SUCCESS);
	else if (keycode == RIGHT_KEY)
	{
		frctl->colour_right = (frctl->colour_right + 1) % 4;
		make_fractol(frctl);
	}
	else if (keycode == LEFT_KEY)
	{
		frctl->colour_right = (frctl->colour_left + 1) % -4;
		make_fractol(frctl);
	}
	else if (keycode == UP_KEY || keycode == DOWN_KEY)
	{
		change_fractol(frctl, keycode);
		make_fractol(frctl);
	}
	return (SUCCESS);
}

void	change_fractol(t_fractol *frctl, int keycode)
{
	char	*real;
	char	*imag;

	if (keycode == UP_KEY && frctl->frctl_type == MANDELBROT)
		frctl->frctl_type = JULIA;
	else if (keycode == UP_KEY && frctl->frctl_type == JULIA)
		frctl->frctl_type = BURNING_SHIP;
	else if (keycode == UP_KEY && frctl->frctl_type == BURNING_SHIP)
		frctl->frctl_type = MANDELBROT;
	else if (keycode == DOWN_KEY && frctl->frctl_type == MANDELBROT)
		frctl->frctl_type = BURNING_SHIP;
	else if (keycode == DOWN_KEY && frctl->frctl_type == JULIA)
		frctl->frctl_type = MANDELBROT;
	else if (keycode == DOWN_KEY && frctl->frctl_type == BURNING_SHIP)
		frctl->frctl_type = JULIA;
	real = "-0.5519839361339869";
	imag = "-0.6213426853707413";
	frctl->julia.real = ft_atod(real);
	frctl->julia.imag = ft_atod(imag);
}

int	mouse_hook(int keycode, int x, int y, t_fractol *frctl)
{
	t_complex	pos;

	if (keycode == SCROLL_OUT || keycode == SCROLL_IN)
	{
		pos.real = frctl->x_min + x * frctl->scale.real;
		pos.imag = frctl->y_max - y * frctl->scale.imag;
		if (keycode == SCROLL_IN)
			frctl->zoom = 1.16;
		else
			frctl->zoom = 0.96;
		frctl->x_min = pos.real + (frctl->x_min - pos.real) * frctl->zoom;
		frctl->x_max = pos.real + (frctl->x_max - pos.real) * frctl->zoom;
		frctl->y_min = pos.imag + (frctl->y_min - pos.imag) * frctl->zoom;
		frctl->y_max = pos.imag + (frctl->y_max - pos.imag) * frctl->zoom;
		make_fractol(frctl);
	}
	return (0);
}
