/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_keys_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:18:18 by allallem          #+#    #+#             */
/*   Updated: 2018/05/21 03:33:03 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				my_mouse_move(int x, int y, t_fractol *p)
{
	double pos_cursor_x;
	double pos_cursor_y;

	if (p->calc > 1)
	{
		pos_cursor_x = p->x_min + (x * ((p->x_max - p->x_min) / WIN_X));
		pos_cursor_y = p->y_max - (y * ((p->y_max - p->y_min) / WIN_Y));
		p->c_r = pos_cursor_x;
		p->c_i = pos_cursor_y;
	}
	return (1);
}

double			my_ft_abs(double x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

void			ft_swap_fractal(t_fractol *p)
{
	if (p->fractal == 1)
	{
		p->x_max = MAX_X_J;
		p->y_min = MIN_Y_J;
		p->y_max = MAX_Y_J;
		p->x_min = MIN_X_J;
		p->c_r = 0.285;
		p->c_i = 0.01;
		p->fractal = 2;
	}
	else if (p->fractal == 2)
	{
		p->x_max = MAX_X_M;
		p->y_min = MIN_Y_M;
		p->y_max = MAX_Y_M;
		p->x_min = MIN_X_M;
		p->fractal = 3;
	}
	else
		ft_swap_fractal_2(p);
}

int				ft_my_key_event(int key, t_fractol *p)
{
	if (key == 49)
		ft_swap_fractal(p);
	if (key == 48 && p->teta < 5)
		p->teta += 0.5;
	else if (key == 48 && p->teta >= 5)
		p->teta = 0;
	if (key == 1 && p->q == 0)
		p->q = 1;
	else if (key == 1 && p->q == 1)
		p->q = 0;
	if (key == 15)
	{
		if (p->fractal != 1 && p->rand == 0)
			p->rand = 1;
		else
		{
			ft_assign_color(p);
			p->rand = 0;
		}
	}
	ft_my_key_event2(key, p);
	return (0);
}

int				ft_mouse_event(int key, int x, int y, t_fractol *p)
{
	double pos_cursor_x;
	double pos_cursor_y;

	ft_mouse_event2(key, p);
	pos_cursor_x = p->x_min + (x * ((p->x_max - p->x_min) / WIN_X));
	pos_cursor_y = p->y_max - (y * ((p->y_max - p->y_min) / WIN_Y));
	if (key == 4)
	{
		p->x_max = pos_cursor_x + ((p->x_max - pos_cursor_x) * 1.2);
		p->y_max = pos_cursor_y + ((p->y_max - pos_cursor_y) * 1.2);
		p->x_min = pos_cursor_x - ((pos_cursor_x - p->x_min) * 1.2);
		p->y_min = pos_cursor_y - ((pos_cursor_y - p->y_min) * 1.2);
		p->calc = 1;
	}
	if (key == 5 && p->dy > 0.000000000000001 && p->dx > 0.000000000000001)
	{
		p->x_max = pos_cursor_x + ((p->x_max - pos_cursor_x) / 1.2);
		p->y_max = pos_cursor_y + ((p->y_max - pos_cursor_y) / 1.2);
		p->x_min = pos_cursor_x - ((pos_cursor_x - p->x_min) / 1.2);
		p->y_min = pos_cursor_y - ((pos_cursor_y - p->y_min) / 1.2);
		p->calc = 1;
	}
	return (1);
}
