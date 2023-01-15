/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:44:15 by sreinhol          #+#    #+#             */
/*   Updated: 2022/01/17 16:59:08 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_mlx(t_fractol *frctl)
{
	frctl->mlx_ptr = mlx_init();
	if (frctl->mlx_ptr == NULL)
		close_fractol(frctl);
	frctl->win_ptr = mlx_new_window(frctl->mlx_ptr, WIDTH, HEIGHT, "fractol");
	if (frctl->win_ptr == NULL)
		close_fractol(frctl);
	frctl->mlx_img = mlx_new_image(frctl->mlx_ptr, WIDTH, HEIGHT);
	if (frctl->mlx_img == NULL)
		close_fractol(frctl);
	frctl->addr = mlx_get_data_addr(frctl->mlx_img, &frctl->bits_per_pixel,
			&frctl->line_length, &frctl->endian);
	if (frctl->addr == NULL)
		close_fractol(frctl);
	mlx_hook(frctl->win_ptr, 2, 0, key_hook, frctl);
	mlx_hook(frctl->win_ptr, 4, 0, mouse_hook, frctl);
}

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	t_fractol	*frctl;

	frctl = frctl_init(argc, argv);
	if (check_input(frctl, argc, argv) == FAILED)
		return (0);
	start_mlx(frctl);
	make_fractol(frctl);
	mlx_loop(frctl->mlx_ptr);
}
