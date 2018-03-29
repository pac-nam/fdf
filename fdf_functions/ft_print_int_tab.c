/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:41:03 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/29 19:17:13 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../header/fdf.h"

int		ft_print_int_tab(int **map)
{
	int		y;
	int		x;

	y = 1;
	ft_printf("%d", map[0][0]);
	while (y <= map[0][0])
	{
		ft_putchar('\n');
		x = 0;
		while (x <= map[y][0])
			ft_printf("%4d", map[y][x++]);
		++y;
	}
	ft_putchar('\n');
	return (0);
}
