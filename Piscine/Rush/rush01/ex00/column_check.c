/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:27:29 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/09 22:46:14 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	prom_col(int y, int x, int (*res_arr)[6])
{
	int	cnt;
	int	max_num;
	int	i;

	i = 0;
	cnt = 1;
	max_num = res_arr[1][x];
	while (++i < y)
		if (res_arr[i][x] == res_arr[y][x])
			return (0);
	i = 0;
	while (++i < y)
	{
		if (max_num < res_arr[i + 1][x])
		{
			cnt ++;
			max_num = res_arr[i + 1][x];
		}
		if (cnt > res_arr[0][x])
			return (0);
	}
	if (cnt + (4 - y) < res_arr[0][x])
		return (0);
	return (1);
}

int	prom_col_rev(int y, int x, int (*res_arr)[6])
{
	int	max_num;
	int	cnt;
	int	i;

	max_num = res_arr[y][x];
	cnt = 1;
	i = y + 1;
	while (--i > 0)
	{
		if (max_num < res_arr[i - 1][x])
		{
			cnt++;
			max_num = res_arr[i - 1][x];
		}
		if (cnt > res_arr[y + 1][x])
			return (1);
	}
	if (cnt != res_arr[y + 1][x])
		return (1);
	return (0);
}
