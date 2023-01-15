/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:19:36 by sreinhol          #+#    #+#             */
/*   Updated: 2022/01/17 16:22:44 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_input(t_fractol *frctl, int argc, char **argv)
{
	frctl->frctl_type = 0;
	if (argc == 4 && !ft_strncmp(argv[1], "Julia", 6))
		return (julia_helper(frctl, argv));
	else if (argc == 2 && (!ft_strncmp(argv[1], "Mandelbrot", 11)
			 || (!ft_strncmp(argv[1], "BurningShip", 13))))
	{
		if (!ft_strncmp(argv[1], "Mandelbrot", 11))
			frctl->frctl_type = MANDELBROT;
		if (!ft_strncmp(argv[1], "BurningShip", 13))
			frctl->frctl_type = BURNING_SHIP;
		return (SUCCESS);
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "Julia", 6))
		return (julia_helper_2(frctl, argv));
	else
	{
		error_msg();
		free_struct(frctl);
		return (FAILED);
	}
	if (frctl->frctl_type == 0)
	{
		free_struct(frctl);
		return (FAILED);
	}
}

int	julia_helper(t_fractol *frctl, char **argv)
{
	frctl->frctl_type = JULIA;
	frctl->julia.real = ft_atod(argv[2]);
	if (fabs(frctl->julia.real) > 2)
	{
		error_msg();
		free_struct(frctl);
		return (FAILED);
	}
	check_parameter(frctl, argv[3]);
	frctl->julia.imag = ft_atod(argv[3]);
	if (fabs(frctl->julia.imag) > 2)
	{
		error_msg();
		free_struct(frctl);
		return (FAILED);
	}
	return (SUCCESS);
}

int	check_parameter(t_fractol *frctl, char	*str)
{
	if (str[0] == '-')
	{
		if (str[1] > '2' || str[2] != '.')
		{
			error_msg();
			free_struct(frctl);
			return (FAILED);
		}
	}
	else
	{
		if (str[0] > '2' || str[1] != '.')
		{
			error_msg();
			free_struct(frctl);
			return (FAILED);
		}
	}
	return (SUCCESS);
}

int	julia_helper_2(t_fractol *frctl, char **argv)
{
	char	*real;
	char	*imag;

	real = "-0.5519839361339869";
	imag = "-0.6213426853707413";
	frctl->frctl_type = JULIA;
	frctl->julia.real = ft_atod(real);
	frctl->julia.imag = ft_atod(imag);
	return (SUCCESS);
}

void	error_msg(void)
{
	printf("\033[0;31m");
	printf("Input is not valid\n"
		"Please choose one of the following options:\n"
		"__________________________________________\n"
		"\n"
		"[ Mandelbrot, Julia, BurningShip ]\n"
		"\n"
		"Choose the c value for the Julia fractol "
		"by providing the real and imaginary part.\n"
		"Both values should be in the range of -2 to 2.\n");
}
