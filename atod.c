/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:18:29 by sreinhol          #+#    #+#             */
/*   Updated: 2022/01/17 16:18:58 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	my_atoi(char *str)
{
	double	nbr;

	nbr = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		nbr *= 10;
		nbr += *str - '0';
		str++;
	}
	return (nbr);
}

double	add_pos_comma(char *str, int i, int j, double pre_comma)
{
	double	post_comma;
	double	nbr;

	post_comma = my_atoi(&str[i]);
	while (fabs(post_comma) > 1)
		post_comma = post_comma / 10;
	if (str[0] != '-')
		nbr = pre_comma + (post_comma / j);
	else
		nbr = pre_comma - (post_comma / j);
	return (nbr);
}

double	ft_atod(char *str)
{
	double	pre_comma;
	int		i;
	int		j;

	i = 0;
	if (str[0] == '-')
	{
		i++;
		pre_comma = (str[i] - '0') * (-1);
	}
	else
		pre_comma = str[i] - '0';
	i++;
	if (str[i] == '.')
		i++;
	j = 1;
	while (str[i] == '0')
	{
		j = j * 10;
		i++;
	}
	return (add_pos_comma(str, i, j, pre_comma));
}
