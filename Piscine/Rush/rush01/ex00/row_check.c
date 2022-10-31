/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:38:17 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/09 20:44:08 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	prom_row(int y, int x, int (*res_arr)[6])
{
	int	cnt;
	int	max_num;
	int	i;

	i = 0;
	cnt = 1;
	max_num = res_arr[y][1];
	while (++i < x)
		if (res_arr[y][i] == res_arr[y][x])
			return (0);
	i = 0;
	while (++i < x)
	{
		if (max_num < res_arr[y][i + 1])
		{
			cnt ++;
			max_num = res_arr[y][i + 1];
		}
		if (cnt > res_arr[y][0])
			return (0);
	}
	if (cnt + (4 - x) < res_arr[y][0])
		return (0);
	return (1);
}

int	prom_row_rev(int y, int x, int (*res_arr)[6])
{
	int	max_num;
	int	cnt;
	int	i;

	max_num = res_arr[y][x];
	cnt = 1;
	i = x + 1;
	while (--i > 0)
	{
		if (max_num < res_arr[y][i - 1])
		{
			cnt++;
			max_num = res_arr[y][i - 1];
		}
		if (cnt > res_arr[y][x + 1])
			return (1);
	}
	if (cnt != res_arr[y][x + 1])
		return (1);
	return (0);
}
