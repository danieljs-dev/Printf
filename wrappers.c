/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:00:45 by dajesus-          #+#    #+#             */
/*   Updated: 2024/11/12 04:03:44 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(va_list args)
{
	int		value;
	int		len;
	int		tmp_value;

	len = 0;
	value = va_arg(args, int);
	tmp_value = value;
	if (value == INT_MIN)
		return (ft_putstr_fd("-2147483648", 1), 11);
	if (value < 0)
	{
		len++;
		tmp_value = -tmp_value;
	}
	if (value == 0)
		return (ft_putchar_fd('0', 1) , 1);
	while (tmp_value > 0)
	{
		tmp_value = tmp_value / 10;
		len++;
	}
	ft_putnbr_fd(value, 1);
	return (len);
}

int	print_unsigned_dec(va_list args)
{
	unsigned int		value;
	int					count;

	count = 0;
	value = va_arg(args, unsigned int);
	count += ft_putunsigned_dec_fd(value, 1);
	return (count);
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
	uintptr_t		ptr_value;
	int				count;

	count = 0;
	ptr_value = (uintptr_t)va_arg(args, void *);
	if (ptr_value == 0)
	{
		ft_putstr_fd("(nil)" ,1);
		return (ft_strlen("(nil)"));
	}
	ft_putstr_fd("0x", 1);
	count += 2;
	count += ft_putunsigned_hex_fd(ptr_value, HEX_LOWER, 1);
	return (count);
}

int	print_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (ft_strlen("(null)"));
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	print_char(va_list args)
{
	char		c;

	c = (char)va_arg(args, int);
	ft_putchar_fd(c, 1);
	return (1);
}
