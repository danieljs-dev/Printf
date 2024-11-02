/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:36:47 by dajesus-          #+#    #+#             */
/*   Updated: 2024/11/02 08:06:41 by dajesus-         ###   ########.fr       */
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
		ft_putchar_fd('%', 1);
		//ft_putchar_fd(specifier, 1);
		return (1);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	int				count;
	int				i;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += handle_specifier(str[i + 1], ap);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}

/*
cc ft_printf.c wrappers.c specifiers.c libft/ft_putchar_fd.c libft/ft_itoa.c libft/ft_putstr_fd.c libft/ft_strlen.c libft/ft_strchr.c
*/

#include <stdio.h>
#include <limits.h>

int	main(void)
{
	//unsigned int small_value = 42;
	//unsigned int large_value = 4000000000;
	//unsigned int max_value = UINT_MAX;
	
	ft_printf("Hello %s, you have %% new messages.\n", "Alice", 5);
	ft_printf("Hello %s, you have %j new messages.\n", "Alice", 5);
	//ft_printf("Unsigned small value: %u\n", small_value);
	//ft_printf("Unsigned large value: %u\n", large_value);
	//ft_printf("Unsigned max value: %u\n", max_value);
	
	return (0);
}
