/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngamkri <wngamkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 12:59:02 by wngamkri          #+#    #+#             */
/*   Updated: 2026/09/07 11:11:32 by wngamkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_rtn(int n)
{
	int		len;
	long	nb;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		len += ft_putchar_rtn('-');
		nb = -nb;
	}
	if (nb >= 10)
		len += ft_putnbr_rtn(nb / 10);
	len += ft_putchar_rtn(nb % 10 + '0');
	return (len);
}

int	ft_putunsigned_rtn(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_putunsigned_rtn(n / 10);
	len += ft_putchar_rtn(n % 10 + '0');
	return (len);
}
