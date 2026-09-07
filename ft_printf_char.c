/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngamkri <wngamkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 09:23:52 by wngamkri          #+#    #+#             */
/*   Updated: 2026/09/07 12:44:50 by wngamkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar_rtn(int c)
{
    return (write(1, &c, 1));
}

int	ft_putstr_rtn(char *str)
{
	int	len;

	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}
	len = 0;
	while (str[len])
		len++;
	return (write(1, str, len));
}
