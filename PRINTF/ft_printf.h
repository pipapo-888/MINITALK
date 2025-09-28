/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 23:22:29 by knomura           #+#    #+#             */
/*   Updated: 2025/05/25 13:49:10 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr(int n);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_put_unsigned_nbr(unsigned int plus_num);
int		ft_puthex(unsigned int num);
int		ft_puthex_upper(unsigned int num);
int		ft_puthex_ptr(unsigned long addr, int i);

#endif
