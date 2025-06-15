/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeybek <vzeybek@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:00:19 by vzeybek           #+#    #+#             */
/*   Updated: 2025/03/08 14:54:18 by vzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	is_valid_char(char c)
{
	if (c != '+' && c != '-' && !is_space(c))
		return (1);
	return (0);
}

int	check_base(char *base)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (base[len])
		len++;
	if (len < 2)
		return (0);
	while (base[i])
	{
		if (!is_valid_char(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j++])
				return (0);
		}
		i++;
	}
	return (len);
}

int	get_digit(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		else
			i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	result;
	int	base_len;
	int	digit;
	int	sign;

	i = 0;
	sign = 1;
	result = 0;
	base_len = check_base(base);
	if (base_len == 0)
		return (0);
	while (is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i] == '+' || str[i] == '-')
			sign *= -1;
	digit = get_digit(str[i], base);
	while (digit >= 0)
	{
		result = result * base_len + digit;
		i++;
		digit = get_digit(str[i], base);
	}
	return (result * sign);
}
