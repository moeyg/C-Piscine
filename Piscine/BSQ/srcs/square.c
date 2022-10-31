/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:41:20 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/20 08:41:22 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**map_dp_init(t_map *map)
{
	int	row;
	int	col;
	int	**memo;

	memo = (int **)safe_malloc(sizeof(int *) * (map->height));
	row = -1;
	while (++row < map->height)
	{
		memo[row] = (int *)safe_malloc(sizeof(int) * (map->width));
		col = -1;
		while (++col < map->width)
		{
			if (map->arr[row][col] == map->obstacle)
				memo[row][col] = 0;
			else
				memo[row][col] = 1;
		}
	}
	return (memo);
}

void	set_square(t_square *square, int col, int row, int len)
{
	square->col = col;
	square->row = row;
	square->len = len;
}

int	check_square(int row, int col, int **memo)
{
	int	min;
	int	top;
	int	top_left;
	int	left;

	top = memo[row - 1][col];
	top_left = memo[row - 1][col - 1];
	left = memo[row][col - 1];
	min = get_min(top, top_left, left);
	memo[row][col] = min + 1;
	return (min + 1);
}

void	find_square_dp(t_map *map, t_square *square, int **memo)
{
	int	row;
	int	col;
	int	len;

	row = -1;
	while (++row < map->height)
	{
		col = -1;
		while (++col < map->width)
		{
			if (row == 0 || col == 0)
			{
				if (square->len < memo[row][col])
					set_square(square, col, row, memo[row][col]);
				continue ;
			}
			if (memo[row][col] == 1)
			{
				len = check_square(row, col, memo);
				if (square->len < len)
					set_square(square, col, row, len);
			}
		}
	}
}

t_square	*find_square(t_map *map_info)
{
	int			index;
	int			**memo;
	t_square	*square;

	square = (t_square *)safe_malloc(sizeof(t_square));
	memo = map_dp_init(map_info);
	set_square(square, -1, -1, 0);
	find_square_dp(map_info, square, memo);
	index = 0;
	while (index < map_info->height)
		free(memo[index++]);
	free(memo);
	return (square);
}
