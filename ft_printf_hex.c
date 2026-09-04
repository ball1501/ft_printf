/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngamkri <wngamkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 13:16:06 by wngamkri          #+#    #+#             */
/*   Updated: 2026/09/04 13:58:48 by wngamkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_rtn(unsigned long num, char *base)
{
	int	len;

	len = 0;
	if (num >= 16)
		len += ft_puthex_rtn(num / 16, base);
	len += ft_putchar_rtn(base[num % 16]);
	return (len);
}

int	ft_putptr_rtn(unsigned long ptr)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (!ptr)
		return (write(1, "(nil)", 5));
	len += ft_putstr_rtn("0x");
	len += ft_puthex_rtn(ptr, base);
	return (len);
}
