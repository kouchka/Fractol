/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:51:26 by allallem          #+#    #+#             */
/*   Updated: 2018/05/21 06:25:29 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <pthread.h>
# include <time.h>
# define ITERATION_MAX 50
# define MAX_X_M 0.6
# define MIN_X_M -2.1
# define MAX_Y_M 1.2
# define MIN_Y_M -1.2
# define MAX_X_J 1
# define MIN_X_J -1
# define MAX_Y_J 1.2
# define MIN_Y_J -1.2
# define WIN_X 750
# define WIN_Y 750
# define THREAD 8

typedef struct		s_fractol
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned char	*data;
	int				bpp;
	int				endian;
	int				size_line;
	int				fractal;
	int				calc;
	int				iteration;
	double			y;
	double			x;
	double			dx;
	double			dy;
	double			c_i;
	double			c_r;
	double			z_r;
	double			z_i;
	int				pixelx;
	int				pixely;
	double			x_max;
	double			x_min;
	double			y_max;
	double			y_min;
	int				i;
	int				rand;
	int				q;
	double			teta;
	int				tab[8];
}					t_fractol;

typedef struct		s_thread
{
	int				number;
	int				pixely;
	int				pixelx;
	double			tmp;
	double			temp;
	double			x;
	double			y;
	t_fractol		*p;
}					t_thread;

void				ft_trace(int i);
void				ft_error(int i);
void				ft_init(t_fractol *p);
int					ft_game(t_fractol *p);
int					ft_my_key_event(int key, t_fractol *p);
int					ft_mouse_event(int key, int x, int y, t_fractol *p);
void				ft_retrace_mendel(t_fractol *p);
void				ft_reset_image(t_fractol *p);
void				ft_put_pixel_image_spe(t_thread *p, int i);
double				my_ft_abs(double x);
void				ft_free_all(t_thread **p, pthread_t *tab);
void				ft_go_on_thread(t_thread **s, pthread_t *t, t_fractol *p,
						void *f);
void				*ft_work_m(void *value);
void				*ft_work_j(void *value);
void				*ft_work_b(void *value);
void				ft_trace_julia(t_fractol *p);
int					my_mouse_move(int x, int y, t_fractol *p);
void				ft_trace_my_bonus(t_fractol *p);
void				ft_swap_color(t_fractol *p);
void				ft_assign_color(t_fractol *p);
void				ft_rand(t_thread *p);
void				ft_swap_fractal_2(t_fractol *p);
void				ft_my_key_event2(int key, t_fractol *p);
void				ft_mouse_event2(int key, t_fractol *p);
void				ft_trace_my_bonus2(t_fractol *p);
void				*ft_work_b2(void *value);

#endif
