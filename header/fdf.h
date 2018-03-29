/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:34:30 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/29 16:41:59 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../ressources/minilibx_macos/mlx.h"
# include "../libft/header/libft.h"

int		ft_init_map(char *file, int ***map);
int		ft_print_int_tab(int **map);

#endif
