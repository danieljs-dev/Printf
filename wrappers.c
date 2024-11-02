/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:00:45 by dajesus-          #+#    #+#             */
/*   Updated: 2024/11/02 07:13:35 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(va_list args)
{
	int		value;
	int		len;
	char	*str;

	value = va_arg(args, int);
	str = ft_itoa(value);
	if (str)
	{
		ft_putstr_fd(str, 1);
		len = ft_strlen(str);
		free(str);
		return (len);
	}
	return (0);
}

static void	ft_putunsigned_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putunsigned_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

static int	ft_numlen(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	print_unsigned(va_list args)
{
	unsigned int		value;

	value = va_arg(args, unsigned int);
	ft_putunsigned_fd(value, 1);

	return (ft_numlen(value));
}

int	print_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str)
	{
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	return (0);
}

int	print_char(va_list args)
{
	char		c;

	c = (char)va_arg(args, int);
	ft_putchar_fd(c, 1);
	return (1);
}
