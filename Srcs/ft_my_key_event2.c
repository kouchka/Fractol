/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_key_event2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 03:23:39 by allallem          #+#    #+#             */
/*   Updated: 2018/05/21 06:24:51 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mouse_event2(int key, t_fractol *p)
{
	if (key == 1)
	{
		if (p->calc == 1)
			p->calc = 2;
		else if (p->calc == 2)
			p->calc = 1;
	}
}

void	ft_my_key_event2(int key, t_fractol *p)
{
	if (key == 67)
	{
		if (p->fractal == 3)
			p->calc = 1;
		ft_swap_color(p);
	}
	if (key == 69)
	{
		p->iteration += 10;
		if (p->fractal == 1 || p->fractal == 3)
			p->calc = 1;
	}
	if (key == 78)
	{
		p->iteration -= 10;
		if (p->fractal == 1 || p->fractal == 3)
			p->calc = 1;
	}
	if (key == 53)
		exit(EXIT_SUCCESS);
}

void	ft_swap_fractal_2(t_fractol *p)
{
	if (p->fractal == 3)
	{
		p->x_max = 2.8;
		p->y_min = 2.1;
		p->y_max = -2.1;
		p->x_min = -2.8;
		p->fractal = 4;
	}
	else if (p->fractal == 4)
	{
		p->x_max = MAX_X_J;
		p->y_min = MIN_Y_J;
		p->y_max = MAX_Y_J;
		p->x_min = MIN_X_J;
		p->fractal = 5;
	}
	else if (p->fractal == 5)
	{
		p->x_max = MAX_X_M;
		p->y_min = MIN_Y_M;
		p->y_max = MAX_Y_M;
		p->x_min = MIN_X_M;
		p->fractal = 1;
	}
}
