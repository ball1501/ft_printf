/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngamkri <wngamkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 10:09:07 by wngamkri          #+#    #+#             */
/*   Updated: 2026/09/07 13:08:58 by wngamkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_putchar_rtn(va_arg(args, int));
	else if (format == 's')
		print_len += ft_putstr_rtn(va_arg(args, char *));
	else if (format == 'p')
		print_len += ft_putptr_rtn((unsigned long)va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		print_len += ft_putnbr_rtn(va_arg(args, int));
	else if (format == 'u')
		print_len += ft_putunsigned_rtn(va_arg(args, unsigned int));
	else if (format == 'x')
		print_len += ft_puthex_rtn(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		print_len += ft_puthex_rtn(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == '%')
		print_len += ft_putchar_rtn('%');
	return (print_len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		total_len;
	va_list	args;

	i = 0;
	total_len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			total_len += ft_formats(args, format[i]);
		}
		else
		{
			total_len += ft_putchar_rtn(format[i]);
		}
		i++;
	}
	va_end(args);
	return (total_len);
}
