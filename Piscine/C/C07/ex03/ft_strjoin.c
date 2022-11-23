/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 01:12:17 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/17 12:53:24 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_total_strlen(int size, char **strs, char *sep);
char	*ft_strcat(char *dest, char *src);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		index;
	int		total_length;

	index = 0;
	total_length = ft_total_strlen(size, strs, sep);
	result = (char *)malloc(sizeof(char) * (total_length + 1));
	*result = 0;
	while (index < size)
	{
		result = ft_strcat(result, strs[index]);
		if (index + 1 < size)
			result = ft_strcat(result, sep);
		index ++;
	}
	return (result);
}

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length ++;
	return (length);
}

int	ft_total_strlen(int size, char **strs, char *sep)
{
	int	index;
	int	sep_length;
	int	result;

	index = 0;
	sep_length = ft_strlen(sep);
	result = 0;
	while (index < size)
	{
		result += ft_strlen(strs[index]);
		if (index + 1 < size)
			result += sep_length;
		index ++;
	}
	return (result);
}

char	*ft_strcat(char *dest, char *src)
{
	int	index;
	int	dest_length;
	int	src_length;

	index = 0;
	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	while (index < src_length)
	{
		dest[dest_length + index] = src[index];
		index ++;
	}
	dest[dest_length + index] = '\0';
	return (dest);
}
