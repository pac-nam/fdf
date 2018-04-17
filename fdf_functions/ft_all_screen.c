/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 14:44:13 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/16 15:45:32 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int		ft_all_screen(t_stock *s, int color)
{
	int		x;
	int		y;

	y = -1;
	while (++y < s->win_height)
	{
		x = 0;
		while (x < s->win_width)
			mlx_pixel_put(s->mlx, s->win, x++, y, color);
	}
	return (1);
}
