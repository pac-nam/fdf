/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:34:30 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/29 19:11:17 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../ressources/minilibx_macos/mlx.h"
# include "../libft/header/libft.h"

# define WIN_WIDTH 600
# define WIN_HEIGHT 300

typedef struct	s_stock
{
		int		**map;
		float	zoom;
}				t_stock;

int		ft_init_map(char *file, int ***map);
int		ft_print_int_tab(int **map);

#endif
