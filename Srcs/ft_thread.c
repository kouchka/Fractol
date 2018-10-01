/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:58:46 by allallem          #+#    #+#             */
/*   Updated: 2018/05/21 06:08:16 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_free_all(t_thread **p, pthread_t *tab)
{
	int i;

	i = 0;
	while (i < THREAD)
	{
		free(p[i]);
		i++;
	}
	free(tab);
	free(p);
}

void	ft_go_on_thread(t_thread **st, pthread_t *tab, t_fractol *p, void *f)
{
	while (p->i < THREAD)
	{
		if (!(st[p->i] = malloc(sizeof(t_thread))))
			exit(EXIT_SUCCESS);
		st[p->i]->p = p;
		st[p->i]->number = p->i;
		if (pthread_create(&tab[p->i], NULL, (f), st[p->i]))
		{
			perror("Thread failed");
			exit(EXIT_SUCCESS);
		}
		p->i++;
	}
	p->i = 0;
}
