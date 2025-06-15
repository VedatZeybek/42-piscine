/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeybek <vzeybek@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:57:55 by vzeybek           #+#    #+#             */
/*   Updated: 2025/03/12 10:21:17 by vzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	*ft_range(int min, int max)
{
	int	range;
	int	*arr;
	int	i;

	if (min >= max)
		return (NULL);
	i = 0;
	range = max - min;
	arr = (int *)malloc((range) * sizeof(int) + 1);
	if (!arr)
		return (NULL);
	while (i < range)
	{
		arr[i] = min + i;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
