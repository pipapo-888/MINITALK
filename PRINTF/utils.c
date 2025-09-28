/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 23:09:35 by knomura           #+#    #+#             */
/*   Updated: 2025/06/19 13:11:53 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_putnbr(int n)
{
	char	c;
	long	num;
	int		count;

	count = 0;
	num = n;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		count++;
	}
	if (num >= 10)
		count += ft_putnbr(num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	count;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		write(1, s, 1);
		s++;
		count++;
	}
	return (count);
}

int	ft_put_unsigned_nbr(unsigned int plus_num)
{
	char	c;
	int		count;

	count = 0;
	if (plus_num >= 10)
		count += ft_put_unsigned_nbr(plus_num / 10);
	c = plus_num % 10 + '0';
	write(1, &c, 1);
	count++;
	return (count);
}
