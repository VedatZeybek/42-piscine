/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeybek <vzeybek@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:44:09 by vzeybek           #+#    #+#             */
/*   Updated: 2025/02/22 21:00:54 by vzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	num2 = 1;
	while (num1 <= 98)
	{
		while (num2 <= 99)
		{
			ft_putchar(num1 / 10 + 48);
			ft_putchar(num1 % 10 + 48);
			ft_putchar(' ');
			ft_putchar(num2 / 10 + 48);
			ft_putchar(num2 % 10 + 48);
			if (!(num1 == 98 && num2 == 99))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			num2++;
		}
		num1++;
		num2 = num1 + 1;
	}
}
