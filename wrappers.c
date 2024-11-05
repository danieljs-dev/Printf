/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:00:45 by dajesus-          #+#    #+#             */
/*   Updated: 2024/11/04 22:24:20 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putunsigned_dec_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putunsigned_dec_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void	ft_putunsigned_hex_fd(unsigned int n, const char *hex_base, int fd)
{
	if (n >= 16)
		ft_putunsigned_hex_fd(n / 16, hex_base, fd);
	ft_putchar_fd(hex_base[n % 16], fd);	
}

static int	ft_numlen_dec(int n)
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

int	ft_numlen_hex(unsigned int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

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

int	print_unsigned_dec(va_list args)
{
	unsigned int		value;

	value = va_arg(args, unsigned int);
	ft_putunsigned_dec_fd(value, 1);

	return (ft_numlen_dec(value));
}

int	print_unsigned_lower_hex(va_list args)
{
	unsigned int		value;

	value = va_arg(args, unsigned int);
	ft_putunsigned_hex_fd(value, HEX_LOWER, 1);
	return (ft_numlen_hex(value));
}

int	print_unsigned_upper_hex(va_list args)
{
	unsigned int		value;

	value = va_arg(args, unsigned int);
	ft_putunsigned_hex_fd(value, HEX_UPPER, 1);
	return (ft_numlen_hex(value));
}

int	print_pointer(va_list args)
{
	unsigned long		ptr_value;

	ptr_value = (unsigned long)va_arg(args, void *);
	ft_putstr_fd("0x", 1);
	if (ptr_value == 0)
	{
		ft_putchar_fd('0', 1);
		return (3);
	}
	ft_putunsigned_hex_fd(ptr_value, HEX_LOWER, 1);
	return (2 + ft_numlen_hex(ptr_value));
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
