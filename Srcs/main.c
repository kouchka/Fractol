/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:50:38 by allallem          #+#    #+#             */
/*   Updated: 2018/05/21 03:07:04 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_reset_image(t_fractol *p)
{
	mlx_destroy_image(p->mlx, p->img);
	p->img = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	p->data = (unsigned char *)mlx_get_data_addr(p->img,
	&p->bpp, &p->size_line, &p->endian);
}

void		ft_init(t_fractol *p)
{
	p->mlx = mlx_init();
	p->img = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	p->data = (unsigned char *)mlx_get_data_addr(p->img, &p->bpp,
			&p->size_line, &p->endian);
	p->win = mlx_new_window(p->mlx, WIN_X, WIN_Y, "Fractol");
}

int			main(int argc, char **argv)
{
	srand(time(NULL));
	if (argc > 1 && (ft_strequ(argv[1], "-Mandelbrot")
				|| ft_strequ(argv[1], "-M")))
		ft_trace(1);
	else if (argc > 1 && (ft_strequ(argv[1], "-Julia")
				|| ft_strequ(argv[1], "-J")))
		ft_trace(2);
	else if (argc > 1 && (ft_strequ(argv[1], "-Mancolor")
				|| ft_strequ(argv[1], "-MC")))
		ft_trace(3);
	else if (argc > 1 && (ft_strequ(argv[1], "-Bonus")
				|| ft_strequ(argv[1], "-B")))
		ft_trace(4);
	else
		ft_printf("Usage : ./fdf -(Mandelbrot/Julia/Mancolor or M/J/MC)\n");
	return (0);
}
