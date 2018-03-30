/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:08:51 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/30 18:07:14 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static int		ft_put_line_s(int x, int y1, int y2, t_stock *s)
{
	ft_putstr("south\n");
	if (y1 > y2)
		ft_swap(&y1, &y2);
	while (y1 <= y2)
		mlx_pixel_put(s->mlx, s->win, x, y1++, 0xFFFFFF);
	return (1);
}

#include <stdio.h>

static int		ft_put_line_ne(int x1, int y1, int x2, int y2, t_stock *s)
{
	float   e;
	float   to_add;

	e = 0;
	to_add = (float)((float)(y2 - y1) / (float)(x2 - x1));
	printf("to_add %f\n", to_add);
	if (to_add > 1)
		to_add = 1 / to_add;
	ft_putstr("north_east\n");
	while (x1 <= x2)
	{
		while (e <= 0.5 && y1 >= y2)
		{
			mlx_pixel_put(s->mlx, s->win, x1, y1--, 0xFFFFFF);
			e -= to_add;
		}
		e -= 1;
		++x1;
	}
	return (1);
}

static int		ft_put_line_se(int x1, int y1, int x2, int y2, t_stock *s)
{
	float	e;
	float	to_add;

	e = 0;
	to_add = (float)((float)(y2 - y1) / (float)(x2 - x1));
	printf("to_add %f\n", to_add);
	if (to_add > 1)
		to_add = 1 / to_add;
	ft_putstr("south_east\n");
	while (x1 <= x2)
	{
		while (e <= 0.5 && y1 <= y2)
		{
			mlx_pixel_put(s->mlx, s->win, x1, y1++, 0xFFFFFF);
			e += to_add;
		}
		e -= 1;
		++x1;
	}
	return (1);
}

int				ft_put_line(int x1, int y1, int x2, int y2, t_stock *s)
{
	if (x2 < x1)
	{
		ft_swap(&x1, &x2);
		ft_swap(&y1, &y2);
	}
	ft_printf("x1:%d, y1:%d, x2:%d, y2:%d\n", x1, y1, x2, y2);
	if (x1 == x2)
		return (ft_put_line_s(x1, y1, y2, s));
	if (y1 < y2)
		return (ft_put_line_se(x1, y1, x2, y2, s));
	return (ft_put_line_ne(x1, y1, x2, y2, s));
}
