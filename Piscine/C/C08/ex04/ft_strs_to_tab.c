/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:46:45 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/17 19:45:30 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_strdup(char *src);

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int	index;
	t_stock_str	*tab;

	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (tab == 0)
		return (0);
	index = 0;
	while (index < ac)
	{
		tab[index].size = ft_strlen(av[index]);
		tab[index].str = av[index];
		tab[index].copy = ft_strdup(av[index]);
		index ++;
	}
	tab[index].str = 0;
	return (tab);
}

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != 0)
	{
		index ++;
	}
	return (index);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		index;
	int		size;

	dest = malloc(sizeof(char) * (size + 1));
	size = ft_strlen(src);
	if (dest == 0)
		return (0);
	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index ++;
	}
	dest[index] = '\0';
	return (dest);
}
