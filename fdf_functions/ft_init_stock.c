/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:24:14 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/23 15:12:36 by tbleuse          ###   ########.fr       */
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

int			ft_init_stock(t_stock *s, char *file)
{
	float	angle;

	angle = 2;
	s->zoom = 6;
	s->win_height = 1000;
	s->safe = 10;
	s->cam_x = 0;
	s->cam_y = 0;
	s->cam_dif = 50;
	s->mlx = mlx_init();
	if (!(ft_init_map(file, &s->map)))
		return (0);
	s->dif_up_y = (s->win_height / 2 - s->safe) / s->map[0][0];
	s->dif_up_x = s->dif_up_y * angle;
	s->dif_right_y = (s->win_height / 2 - s->safe) / ft_long_line(s->map);
	s->dif_right_x = s->dif_right_y * angle;
	s->ref->x = s->safe;
	s->ref->y = s->win_height / 2;
	s->win_width = (s->map[0][0] - 1) * s->dif_up_x +
		(ft_long_line(s->map) - 1) * s->dif_right_x + s->safe * 2;
	if (s->win_width > 2 * s->win_height)
		s->win_width = 2 * s->win_height;
	s->win = mlx_new_window(s->mlx, s->win_width, s->win_height, "FDF");
	return (1);
}
