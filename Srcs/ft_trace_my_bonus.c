/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_my_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:54:43 by allallem          #+#    #+#             */
/*   Updated: 2018/05/21 06:07:42 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			ft_trace_x_bonus(t_thread *p)
{
	int		i;
	double	zr;
	double	zi;
	double	tmp;

	while (p->x < p->p->x_max)
	{
		zr = p->x;
		zi = p->y;
		i = 0;
		while (zr * zr + zi * zi < 2 && i++ < p->p->iteration)
		{
			tmp = zr;
			zr = -(zr * zr) + (zi * zi);
			zi = -(2 * zi * tmp);
			zr = zr * zr - zi * zi + p->p->c_r;
			zi = 2 * zi * tmp + p->p->c_i;
		}
		if (i < p->p->iteration && p->p->q == 1)
			ft_put_pixel_image_spe(p, zr * zi);
		else if (i < p->p->iteration)
			ft_put_pixel_image_spe(p, i);
		p->pixelx++;
		p->x += p->p->dx;
	}
}

void				*ft_work_b(void *value)
{
	t_thread		*p;
	int				start;
	int				end;

	p = (t_thread*)value;
	start = ((WIN_X * WIN_Y) / THREAD) * p->number;
	end = ((WIN_X * WIN_Y) / THREAD) * (p->number + 1);
	p->pixely = start / WIN_X;
	p->y = p->p->y_max - (((p->p->y_max - p->p->y_min) / THREAD) * p->number);
	while (p->pixely < end / WIN_X)
	{
		p->pixelx = 0;
		p->x = p->p->x_min;
		ft_trace_x_bonus(p);
		p->pixely++;
		p->y -= p->p->dy;
	}
	pthread_exit(NULL);
}

static void			ft_malloc_thread_bonus(t_fractol *p)
{
	pthread_t	*tab;
	t_thread	**st;

	p->i = 0;
	if (THREAD < 0 || THREAD > 8)
	{
		perror("Number of thread is negative or too high");
		exit(EXIT_SUCCESS);
	}
	if (!(tab = malloc(sizeof(pthread_t*) * THREAD))
	|| !(st = malloc(sizeof(t_thread*) * THREAD)))
		exit(EXIT_SUCCESS);
	ft_go_on_thread(st, tab, p, &ft_work_b);
	while (p->i < THREAD)
	{
		if (pthread_join(tab[p->i], NULL))
		{
			perror("Error on Thead join");
			exit(EXIT_SUCCESS);
		}
		p->i++;
	}
	ft_free_all(st, tab);
}

void				ft_trace_my_bonus(t_fractol *p)
{
	if (p->data)
		ft_reset_image(p);
	p->dx = (p->x_max - p->x_min) / WIN_X;
	p->dy = (p->y_max - p->y_min) / WIN_Y;
	ft_malloc_thread_bonus(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}
