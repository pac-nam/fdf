/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:24:14 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/03 21:26:55 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static int	ft_long_line(int **map)
{
	int	i;
	int	save;

	i = 0;
	save = 0;
	while (++i <= map[0][0])
		if (map[i][0] > save)
			save = map[i][0];
	return (save);
}

int	ft_init_stock(t_stock *s, char *file)
{
	s->win_height = 1000;
	s->color = 0xFFFF00;
	s->mlx = mlx_init();
	if (!(ft_init_map(file, &s->map)))
		return (0);
	s->safe = 10;
	s->dif_up = (s->win_height / 2 - s->safe) / s->map[0][0];
	s->dif_right = (s->win_height / 2 - s->safe) / ft_long_line(s->map);
	s->zoom = 2;
	s->ref->x = s->safe;
	s->ref->y = s->win_height / 2; 
	s->win_width = (s->map[0][0] - 1) * s->dif_up +
		(ft_long_line(s->map) - 1) * s->dif_right + s->safe * 2;
	s->win = mlx_new_window(s->mlx, s->win_width, s->win_height, "FDF");
	return (1);
}
