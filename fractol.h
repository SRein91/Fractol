/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:44:39 by sreinhol          #+#    #+#             */
/*   Updated: 2022/01/17 16:26:47 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define ESC_KEY 53
# define UP_KEY 126
# define DOWN_KEY 125
# define LEFT_KEY 123
# define RIGHT_KEY 124

# define SCROLL_IN 4
# define SCROLL_OUT 5

typedef enum e_enum
{
	FAILED = -1,
	SUCCESS = 0,
	HEIGHT = 1000,
	WIDTH = 1000,
	MANDELBROT = 1,
	JULIA = 2,
	BURNING_SHIP = 3,
}	t_enum;

typedef struct s_complex{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_fractol
{
	t_complex	julia;
	t_complex	c;
	t_complex	scale;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*mlx_img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			frctl_type;
	double		x_max;
	double		x_min;
	double		y_max;
	double		y_min;
	int			x_off;
	int			y_off;
	double		x;
	double		y;
	double		zoom;
	int			x_shift;
	int			y_shift;
	int			counter;
	int			colour_right;
	int			colour_left;
}t_fractol;

void		my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
void		start_mlx(t_fractol *frctl);

int			check_input(t_fractol *frctl, int argc, char **argv);
int			julia_helper(t_fractol *frctl, char **argv);
int			check_parameter(t_fractol *frctl, char	*str);
int			julia_helper_2(t_fractol *frctl, char **argv);
void		error_msg(void);

int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			free_struct(t_fractol *frctl);
t_fractol	*frctl_init(int argc, char *argv[]);
void		get_defaults(t_fractol *frctl);
int			close_fractol(t_fractol *frctl);

double		my_atoi(char *str);
double		ft_atod(char *str);
double		add_pos_comma(char *str, int i, int j, double pre_comma);

int			key_hook(int keycode, t_fractol *frctl);
void		change_fractol(t_fractol *frctl, int keycode);
int			mouse_hook(int keycode, int x, int y, t_fractol *frctl);

int			make_fractol(t_fractol *frctl);
void		select_fractol(t_fractol *frctl, size_t x, size_t y);
void		julia_func(t_fractol *frctl, size_t width, size_t height);
void		mandelbrot_func(t_fractol *frctl, size_t width, size_t height);
void		burning_ship_func(t_fractol *frctl, size_t width, size_t height);

#endif
