/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 05:19:51 by knomura           #+#    #+#             */
/*   Updated: 2025/05/23 00:19:33 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int num)
{
	char	c;
	int		count;

	count = 0;
	if (num >= 16)
		count += ft_puthex(num / 16);
	if (num % 16 < 10)
		c = num % 16 + '0';
	else
		c = (num % 16 - 10) + 'a';
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_puthex_upper(unsigned int num)
{
	const char	*hex;
	int			count;

	count = 0;
	hex = "0123456789ABCDEF";
	if (num >= 16)
		count += ft_puthex_upper(num / 16);
	write(1, &hex[num % 16], 1);
	count++;
	return (count);
}

int	ft_puthex_ptr(unsigned long addr, int i)
{
	const char	*hex;
	int			count;

	if (addr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 0;
	if (!i)
	{
		write(1, "0x", 2);
		count += 2;
		i++;
	}
	hex = "0123456789abcdef";
	if (addr >= 16)
		count += ft_puthex_ptr(addr / 16, i);
	write(1, &hex[addr % 16], 1);
	count++;
	return (count);
}
