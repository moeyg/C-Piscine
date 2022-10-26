/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 06:33:39 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/20 08:31:29 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	draw_square_on_map(t_map *map, t_square *square)
{
	int	row;
	int	col;

	row = square->row - square->len;
	while (++row <= square->row)
	{
		col = square->col - square->len;
		while (++col <= square->col)
			map->arr[row][col] = map->full;
	}
}

void	print_answer(t_map *map, t_square *square)
{
	int	index;

	draw_square_on_map(map, square);
	index = 0;
	while (index < map->height)
	{
		ft_putstr(map->arr[index]);
		ft_putchar('\n');
		index++;
	}
}
