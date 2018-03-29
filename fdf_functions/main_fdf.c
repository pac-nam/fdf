/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:24:14 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/29 16:51:40 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../header/fdf.h"

int		main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		**map;

	if (ac < 2)
	{
		write(2, "missing map\n", 12);
		return (0);
	}
	if (!(ft_init_map(av[1], &map)))
			return (0);
	ft_print_int_tab(map);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "WHAAAAAT!?!?!?!");
	mlx_loop(mlx_ptr);
}
