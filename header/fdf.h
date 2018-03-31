/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:34:30 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/30 14:38:19 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../ressources/minilibx_macos/mlx.h"
# include "../libft/header/libft.h"

typedef struct	s_stock
{
		void	*mlx;
		void	*win;
		int	win_width;
		int	win_height;
		int		**map;
		float	zoom;
}				t_stock;

int		ft_init_map(char *file, int ***map);
int		ft_init_stock(t_stock *s, char *file);
int		ft_print_int_tab(int **map);
int		ft_fdf(t_stock *s);
int		ft_put_line(int x1, int y1, int x2, int y2, t_stock *s);

#endif
