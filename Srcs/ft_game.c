/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:15:24 by allallem          #+#    #+#             */
/*   Updated: 2018/05/21 05:44:35 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_swap_color(t_fractol *p)
{
	int i;

	i = 0;
	while (i < 8)
	{
		p->tab[i] = (p->tab[i] >> 8) + ((p->tab[i] & 0x0000FF) << 16);
		i++;
	}
}

int			ft_game(t_fractol *p)
{
	if ((p->fractal == 2 && p->calc > 0))
		ft_trace_julia(p);
	if ((p->fractal == 1 && p->calc > 0) || (p->fractal == 3 && p->calc > 0))
		ft_retrace_mendel(p);
	if (p->fractal == 4 && p->calc > 0)
		ft_trace_my_bonus(p);
	if (p->fractal == 5)
		ft_trace_my_bonus2(p);
	return (1);
}
