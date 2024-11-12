/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:36:47 by dajesus-          #+#    #+#             */
/*   Updated: 2024/11/12 04:39:20 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_specifier(char specifier, va_list ap)
{
	t_print_func		func;

	func = find_function(specifier);
	if (func)
		return (func(ap));
	else
	{
		ft_putchar_fd('%', STDOUT_FILENO);
		return (1);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	int				count;
	int				i;

	if (!str)
		return (-1);
	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += handle_specifier(str[i + 1], ap);
			i += 2;
			continue ;
		}
		count += ((str[i] != '%') * (ft_putchar_fd(str[i], STDOUT_FILENO), 1));
		i++;
	}
	va_end(ap);
	return (count);
}

// https://onlinegdb.com/eH9mC5MQf