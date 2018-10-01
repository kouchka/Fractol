/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 16:55:04 by allallem          #+#    #+#             */
/*   Updated: 2018/05/21 05:47:45 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_assign_color(t_fractol *p)
{
	p->tab[0] = 0xDD2C10;
	p->tab[1] = 0xC1270E;
	p->tab[2] = 0xA6210C;
	p->tab[3] = 0x8A1B0A;
	p->tab[4] = 0x6E1608;
	p->tab[5] = 0x531006;
	p->tab[6] = 0x370B04;
	p->tab[7] = 0xFE0800;
}

void			ft_put_pixel_image_spe(t_thread *p, int i)
{
	int x;
	int color;

	color = 0;
	if (p->p->fractal != 1)
		color = p->p->tab[i % 8];
	else
		color = 0x00FF00;
	x = p->pixely * p->p->size_line + p->pixelx * (p->p->bpp / 8);
	if (x > ((WIN_X * WIN_Y) * 4))
		return ;
	p->p->data[x] = color & 0xFF;
	p->p->data[x + 1] = color >> 8 & 0xFF;
	p->p->data[x + 2] = color >> 16 & 0xFF;
}

void			ft_choose_2(int i, t_fractol *p)
{
	if (i == 3)
	{
		p->x_max = MAX_X_M;
		p->y_min = MIN_Y_M;
		p->y_max = MAX_Y_M;
		p->x_min = MIN_X_M;
		p->fractal = 3;
		ft_retrace_mendel(p);
	}
	else if (i == 4)
	{
		p->x_max = 2.8;
		p->y_min = -2.1;
		p->y_max = 2.1;
		p->x_min = -2.8;
		p->c_r = 0.123;
		p->c_i = 0.745;
		p->fractal = 4;
		ft_trace_my_bonus(p);
	}
}

void			ft_choose(int i, t_fractol *p)
{
	if (i == 1)
	{
		p->x_max = MAX_X_M;
		p->y_min = MIN_Y_M;
		p->y_max = MAX_Y_M;
		p->x_min = MIN_X_M;
		p->fractal = 1;
		ft_retrace_mendel(p);
	}
	else if (i == 2)
	{
		p->x_max = MAX_X_J;
		p->y_min = MIN_Y_J;
		p->y_max = MAX_Y_J;
		p->x_min = MIN_X_J;
		p->c_r = 0.285;
		p->c_i = 0.01;
		p->fractal = 2;
		ft_trace_julia(p);
	}
	else
		ft_choose_2(i, p);
}

void			ft_trace(int i)
{
	t_fractol *p;

	if (!(p = malloc(sizeof(t_fractol))))
		return (ft_error(1));
	ft_bzero(p, sizeof(t_fractol));
	ft_assign_color(p);
	p->iteration = ITERATION_MAX;
	ft_init(p);
	ft_choose(i, p);
	p->calc = 2;
	mlx_hook(p->win, 6, (1L << 6), my_mouse_move, p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_key_hook(p->win, ft_my_key_event, p);
	mlx_mouse_hook(p->win, ft_mouse_event, p);
	mlx_loop_hook(p->mlx, ft_game, p);
	mlx_loop(p->mlx);
}
