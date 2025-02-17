/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:06:55 by malbayra          #+#    #+#             */
/*   Updated: 2025/02/17 08:33:45 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_u(unsigned int u);
int	ft_pointer(unsigned long p);
int	ft_hex(unsigned int x, int b);
int	ft_check(char c, va_list arg);
int	ft_printf(const char *str, ...);

#endif