/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:46:17 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/30 18:07:16 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int		ft_fdf(t_stock *s)
{
	int	x1 = s->win_width / 2;
	int	x2 = s->win_width / 2;
	int	y1 = s->win_height / 2;
	int	y2 = 0;
	int	change = 3;

	while (y2 <= y1)
	{
		ft_put_line(x1, y1, x2, y2, s);
		x2 += change;
		y2 += change;
	}
	while (y2 <= s->win_height)
	{
		ft_put_line(x1, y1, x2--, y2++, s);
		x2 -= change;
		y2 += change;
	}
	while (y2 >= y1)
	{
		ft_put_line(x1, y1, x2--, y2--, s);
		x2 -= change;
		y2 -= change;
	}
	while (y2 >= 0)
	{
		ft_put_line(x1, y1, x2++, y2--, s);
		x2 += change;
		y2 -= change;
	}
	return (1);
}
