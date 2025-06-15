/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeybek <vzeybek@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:51:18 by vzeybek           #+#    #+#             */
/*   Updated: 2025/03/11 16:54:24 by vzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] && is_sep(str[i], charset))
		i++;
	while (str[i])
	{
		if (!is_sep(str[i], charset))
			count++;
		while (str[i] && !is_sep(str[i], charset))
			i++;
		i++;
	}			
	return (count);
}

int	word_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (str[len] && !is_sep(str[len], charset))
		len++;
	return (len);
}

char	**malloc_words(char *str, char *charset)
{
	int		word_count;
	char	**result;

	word_count = count_words(str, charset);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		len;
	char	**result;

	result = malloc_words(str, charset);
	i = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str)
		{
			len = word_len(str, charset);
			result[i] = (char *)malloc(len + 1);
			if (!result)
				return (NULL);
			j = 0;
			while (j < len)
				result[i][j++] = *str++;
			result[i++][j] = '\0';
		}
	}
	result[i] = NULL;
	return (result);
}
