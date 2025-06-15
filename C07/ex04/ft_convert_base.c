/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeybek <vzeybek@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:14:02 by vzeybek           #+#    #+#             */
/*   Updated: 2025/03/11 20:17:29 by vzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		is_valid_base(char *base);
int		get_index(char c, char *base);
int		ft_atoi_base(char *str, char *base);
char	*ft_itoa_base(int nbr, char *base_to);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		decimal;
	char	*result;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (NULL);
	decimal = ft_atoi_base(nbr, base_from);
	result = ft_itoa_base(decimal, base_to);
	return (result);
}

int	ft_count_digits(int nbr, int base_len)
{
	int		count;
	long	n;

	count = 1;
	n = nbr;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n >= base_len)
	{
		n /= base_len;
		count++;
	}
	return (count);
}

void	ft_fill_result(char *result, long n, char *base_to, int digit_count)
{
	int	base_len;

	base_len = ft_strlen(base_to);
	if (n == 0)
		result[0] = base_to[0];
	while (n > 0)
	{
		digit_count--;
		result[digit_count] = base_to[n % base_len];
		n /= base_len;
	}
}

char	*ft_itoa_base(int nbr, char *base_to)
{
	char	*result;
	int		base_len;
	int		digit_count;
	long	n;

	base_len = ft_strlen(base_to);
	digit_count = ft_count_digits(nbr, base_len);
	result = (char *)malloc(sizeof(char) * (digit_count + 1));
	if (!result)
		return (NULL);
	result[digit_count] = '\0';
	n = nbr;
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	ft_fill_result(result, n, base_to, digit_count);
	return (result);
}
