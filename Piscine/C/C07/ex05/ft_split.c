/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 04:13:47 by dogpark           #+#    #+#             */
/*   Updated: 2022/10/18 04:38:08 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_check_charset(char str, char *charset);
int	ft_count_words(char *str, char *charset);
void	ft_strncpy(char *dest, char *src, int n);

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int	index;
	char	*string;

	index = 0;
	result = (char **)malloc(sizeof(char *) * ft_count_words(str, charset) + 1);
	while (*str)
	{
		if (!ft_check_charset(*str, charset))
		{
			string = str;
			while (*str && !ft_check_charset(*str, charset))
				str ++;
			result[index] = (char *)malloc(str - string + 1);
			ft_strncpy(result[index], string, str - string);
			index ++;
		}
		else
			str ++;
	}
	result[index] = 0;
	return (result);
}

int	ft_check_charset(char str, char *charset)
{
	while (*charset)
	{
		if (str == *charset)
			return (1);
		charset ++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (!ft_check_charset(*str, charset))
		{
			count ++;
			while (*str && !ft_check_charset(*str, charset))
				str ++;
		}
		str ++;
	}
	return (count);
}

void	ft_strncpy(char *dest, char *src, int n)
{
	int	index;

	index = 0;
	while (src[index] != '\0' && index < n)
	{
		dest[index] = src[index];
		index ++;
	}
	dest[index] = '\0';
}
