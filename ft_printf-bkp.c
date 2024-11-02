/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:36:47 by dajesus-          #+#    #+#             */
/*   Updated: 2024/11/02 07:57:37 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	t_print_func	func;
	int				i;
	int				count;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			func = find_function(str[i]);
			if (func)
				count += func(ap);
			else
			{
				ft_putchar_fd('%', 1);
				ft_putchar_fd(str[i], 1);
				count += 1;
			}
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

//#include <stdio.h>

int	main(void)
{
	ft_printf("Hello %s, you have %% new messages.\n", "Alice", 'a');
	return (0);
}
