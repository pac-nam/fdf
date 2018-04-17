/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:34:30 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/16 15:01:46 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../ressources/minilibx_macos/mlx.h"
# include "../libft/header/libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_stock
{
		void	*mlx;
		void	*win;
		int		win_width;
		int		win_height;
		int		**map;
		int		safe;
		int		dif_up_x;
		int		dif_up_y;
		int		dif_right_x;
		int		dif_right_y;
		int		cam_x;
		int		cam_y;
		int		cam_dif;
		float	zoom;
		t_point	*ref;
}				t_stock;

int		ft_init_map(char *file, int ***map);
int		ft_init_stock(t_stock *s, char *file);
int		ft_print_int_tab(int **map);
int		ft_fdf(t_stock *s);
int		ft_all_screen(t_stock *s, int color);
int		ft_put_line(t_point *p1, t_point *p2, t_stock *s);

#endif
