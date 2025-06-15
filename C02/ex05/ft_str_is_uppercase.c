/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeybek <vzeybek@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:14:57 by vzeybek           #+#    #+#             */
/*   Updated: 2025/03/01 16:46:20 by vzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	index;

	if (!str || *str == '\0')
		return (1);
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] > 'Z' || str[index] < 'A')
			return (0);
		index++;
	}
	return (1);
}
