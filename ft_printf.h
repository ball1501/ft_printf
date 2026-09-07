/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wngamkri <wngamkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 10:51:44 by wngamkri          #+#    #+#             */
/*   Updated: 2026/09/07 15:53:58 by wngamkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_putchar_rtn(int c);
int	ft_putstr_rtn(char *str);
int	ft_putnbr_rtn(long n);
int	ft_putunsigned_rtn(unsigned int n);
int	ft_puthex_rtn(unsigned long num, char *base);
int	ft_putptr_rtn(unsigned long ptr);

#endif
