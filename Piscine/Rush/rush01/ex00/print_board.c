/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:41:05 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/09 20:47:40 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_board(int (*res_arr)[6]);
void	make_board(int (*res_arr)[6], int *temp_input);
int		prom_row(int y, int x, int (*res_arr)[6]);
int		prom_row_rev(int y, int x, int (*res_arr)[6]);
int		prom_col(int y, int x, int (*res_arr)[6]);
int		prom_col_rev(int y, int x, int (*res_arr)[6]);

void	make_board(int (*res_arr)[6], int *temp_input)
{
	int	i;
	int	idx;

	i = -1;
	while (++i < 16)
	{
		idx = i % 4 + 1;
		if (i / 4 == 0)
			res_arr[0][idx] = temp_input[i];
		else if (i / 4 == 1)
			res_arr[5][idx] = temp_input[i];
		else if (i / 4 == 2)
			res_arr[idx][0] = temp_input[i];
		else if (i / 4 == 3)
			res_arr[idx][5] = temp_input[i];
	}
}

void	dfs(int y, int x, int (*res_arr)[6])
{
	int	i;

	i = 0;
	if (y == 5)
		print_board(res_arr);
	while (++i < 5)
	{
		res_arr[y][x] = i;
		if (prom_row(y, x, res_arr) && prom_col(y, x, res_arr))
		{
			if (x == 4 && prom_row_rev(y, x, res_arr))
				continue ;
			if (y == 4 && prom_col_rev(y, x, res_arr))
				continue ;
			if (x == 4)
				dfs(y + 1, 1, res_arr);
			else
				dfs(y, x + 1, res_arr);
		}
	}
}

void	print_board(int (*res_arr)[6])
{
	char	temp;
	int		i;
	int		j;

	i = 0;
	while (++i < 5)
	{
		j = 0;
		while (++j < 5)
		{
			temp = res_arr[i][j] + '0';
			write (1, &temp, 1);
			write (1, " ", 1);
		}
		write (1, "\n", 1);
	}
	exit(0);
}
