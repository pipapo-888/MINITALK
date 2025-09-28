/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:15:47 by knomura           #+#    #+#             */
/*   Updated: 2025/06/01 19:16:55 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"

int	handle_format(char cdx, va_list *args)
{
	if (cdx == 'd' || cdx == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (cdx == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (cdx == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (cdx == 'u')
		return (ft_put_unsigned_nbr(va_arg(*args, unsigned int)));
	else if (cdx == 'x')
		return (ft_puthex(va_arg(*args, unsigned int)));
	else if (cdx == 'X')
		return (ft_puthex_upper(va_arg(*args, unsigned int)));
	else if (cdx == 'p')
		return (ft_puthex_ptr(va_arg(*args, unsigned long), 0));
	else if (cdx == '%')
		return (write(1, "%", 1));
	return (-1);
}

int	send_to_format(const char *format, va_list *args)
{
	int	i;
	int	len;
	int	temp;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format [i] == '%' && format[i + 1])
		{
			temp = handle_format(format[++i], args);
			if (temp == -1)
				return (-1);
			len += temp;
			i++;
		}
		else if (format[i] == '%')
			return (-1);
		else
		{
			write(1, &format[i++], 1);
			len++;
		}
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	if (!format)
		return (-1);
	va_start(args, format);
	len = send_to_format(format, &args);
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	// int	a;

// 	// a = 42;
//// ft_printf("%u %%Hell%c %dWo%s\n", -1, 'o', 45, "rld");
//	// printf("%u %%Hell%c %dwo%s\n", -1,'o', 45, "rld");

// 	// ft_printf("i am %x years old he is %X years old  %p\n", 253, 32332, &a);
// 	// printf("i am %x years old he is %X years old  %p\n", 253, 32332, &a);

// 	// ft_printf("%c %c %c %c\n", 0, '0', '1', '2');
// 	// printf("%c %c %c %c \n", 0, '0', '1', '2');

// 	// ft_printf("\tmy name is\n");
// 	// printf("\tmy name is\n");

// 	// ft_printf("String: %s\n", (char *)NULL);
// 	// printf("String: %s\n\n\n\n", (char *)NULL);

// 	int ret1, ret2;

//     ret1 = printf("printf   : %s\n", (char *)NULL);
//     ret2 = ft_printf("ft_printf: %s\n", (char *)NULL);
//     printf("→ 文字数: printf=%d, ft_printf=%d\n\n", ret1, ret2);

//     // NULL ptr
//     ret1 = printf("printf   : %p\n", NULL);
//     ret2 = ft_printf("ft_printf: %p\n", NULL);
//     printf("→ 文字数: printf=%d, ft_printf=%d\n\n", ret1, ret2);

//     // -char
//     ret1 = printf("printf   : %c\n", -1);
//     ret2 = ft_printf("ft_printf: %c\n", -1);
//     printf("→ 文字数: printf=%d, ft_printf=%d\n\n", ret1, ret2);

//     // %q
//     ret1 = printf("printf   : %q\n", 42);
//     ret2 = ft_printf("ft_printf: %q\n", 42);
//     printf("→ 文字数: printf=%d, ft_printf=%d\n\n", ret1, ret2);

//     // ⑤ %%
//     ret1 = printf("printf   : %%\n");
//     ret2 = ft_printf("ft_printf: %%\n");
//     printf("→ 文字数: printf=%d, ft_printf=%d\n\n", ret1, ret2);

//     // ⑥ INT_MIN, UINT_MAX
//     ret1 = printf("printf   : %d\n", INT_MIN);
//     ret2 = ft_printf("ft_printf: %d\n", INT_MIN);
//     printf("→ 文字数: printf=%d, ft_printf=%d\n\n", ret1, ret2);

//     ret1 = printf("printf   : %u\n", UINT_MAX);
//     ret2 = ft_printf("ft_printf: %u\n", UINT_MAX);
//     printf("→ 文字数: printf=%d, ft_printf=%d\n\n", ret1, ret2);

//     // ptr 3
//     int x = 42;
//     void *ptr = &x;
//     ret1 = printf("printf   : %p %p %p\n", ptr, ptr, ptr);
//     ret2 = ft_printf("ft_printf: %p %p %p\n", ptr, ptr, ptr);
//     printf("→ 文字数: printf=%d, ft_printf=%d\n\n", ret1, ret2);

//     ret1 = printf("printf   : %c\n", 'A');
//     ret2 = ft_printf("ft_printf: %c\n", 'A');
//     printf("→ 文字数: printf=%d, ft_printf=%d\n\n", ret1, ret2);

//     ret1 = printf("printf   : %s\n", "Hello");
//     ret2 = ft_printf("ft_printf: %s\n", "Hello");
//     printf("→ 文字数: printf=%d, ft_printf=%d\n\n", ret1, ret2);

//     ret1 = printf("printf   : %d\n", -123);
//     ret2 = ft_printf("ft_printf: %d\n", -123);
//     printf("→ 文字数: printf=%d, ft_printf=%d\n\n", ret1, ret2);

//     ret1 = printf("printf   : %u\n", 3000000000U);
//     ret2 = ft_printf("ft_printf: %u\n", 3000000000U);
//     printf("→ 文字数: printf=%d, ft_printf=%d\n\n", ret1, ret2);

//     ret1 = printf("printf   : %x\n", 255);
//     ret2 = ft_printf("ft_printf: %x\n", 255);
//     printf("→ 文字数: printf=%d, ft_printf=%d\n\n", ret1, ret2);

//     ret1 = printf("printf   : %X\n", 255);
//     ret2 = ft_printf("ft_printf: %X\n", 255);
//     printf("→ 文字数: printf=%d, ft_printf=%d\n\n", ret1, ret2);

//     ret1 = printf("printf   : %p\n", &x);
//     ret2 = ft_printf("ft_printf: %p\n", &x);
//     printf("→ 文字数: printf=%d, ft_printf=%d\n\n", ret1, ret2);

//     ret1 = printf("printf   : %s\n", NULL);
//     ret2 = ft_printf("ft_printf: %s\n", NULL);
//     printf("→ 文字数: printf=%d, ft_printf=%d\n\n", ret1, ret2);

//     ret1 = printf("printf   : %", 42);
// 	printf("\n");
//     ret2 = ft_printf("ft_printf: %", 42);
// 	printf("\n");
//     printf("→ 文字数: printf=%d, ft_printf=%d\n\n", ret1, ret2);

// 	ret1 = printf("printf   : %q", 42);
// 	printf("\n");
//     ret2 = ft_printf("ft_printf: %q", 42);
// 	printf("\n");
//     printf("→ 文字数: printf=%d, ft_printf=%d\n\n", ret1, ret2);

//// 	ret1 = printf("printf   : %q\n", 42);
//// 	printf("\n");
////     ret2 = ft_printf("ft_printf: %q\n", 42);
//// 	printf("\n");
////     printf("→ 文字数: printf=%d, ft_printf=%d\n\n", ret1, ret2);

////  ret1 = printf("printf   : %\n", 42);
////	printf("\n");
////     ret2 = ft_printf("ft_printf: %\n", 42);
//// 	printf("\n");
////     printf("→ 文字数: printf=%d, ft_printf=%d\n\n", ret1, ret2);

	// printf(" %    dadadf", 123);
// 	return (0);
// }
