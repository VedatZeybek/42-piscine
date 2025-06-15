/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeybek <vzeybek@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:52:18 by vzeybek           #+#    #+#             */
/*   Updated: 2025/03/11 17:38:50 by vzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(char *str)
{
	char	*cpy;
	int		i;
	int		j;

	i = 0;
	while (str[i])
		i++;
	cpy = (char *)malloc(i + 1);
	if (!cpy)
		return (NULL);
	j = 0;
	while (j <= i)
	{
		cpy[j] = str[j];
		j++;
	}
	return (cpy);
}
