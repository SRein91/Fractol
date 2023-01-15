/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:24:19 by sreinhol          #+#    #+#             */
/*   Updated: 2022/01/17 16:24:52 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	free_struct(t_fractol *frctl)
{
	free(frctl->mlx_ptr);
	free(frctl->win_ptr);
	free(frctl->mlx_img);
	free(frctl->addr);
	free(frctl->mlx_ptr);
	free(frctl);
	exit(EXIT_SUCCESS);
}

t_fractol	*frctl_init(int argc, char *argv[])
{
	t_fractol	*frctl;

	frctl = malloc(sizeof(t_fractol));
	if (frctl == NULL)
	{
		free_struct(frctl);
		return (NULL);
	}
	frctl->mlx_ptr = NULL;
	frctl->win_ptr = NULL;
	frctl->mlx_img = NULL;
	frctl->addr = NULL;
	get_defaults(frctl);
	return (frctl);
}

void	get_defaults(t_fractol *frctl)
{
	frctl->x_off = 0;
	frctl->y_off = 0;
	frctl->x_max = 2.0;
	frctl->x_min = -2.0;
	frctl->y_max = 2.0;
	frctl->y_min = -2.0;
	frctl->colour_right = 1;
	frctl->colour_left = 1;
}

int	close_fractol(t_fractol *frctl)
{
	if (frctl != NULL)
	{
		mlx_destroy_window(frctl->mlx_ptr, frctl->win_ptr);
		mlx_destroy_image(frctl->mlx_ptr, frctl->mlx_img);
	}
	free_struct(frctl);
	free(frctl);
	exit(EXIT_SUCCESS);
}
