/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:22:04 by dajesus-          #+#    #+#             */
/*   Updated: 2024/11/12 02:56:12 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_to_ascii(int n)
{
	if (n < 0)
		n = -n;
	return (n + '0');
}

char	*ft_itoa(int n)
{
	int		sign;
	int		digits_len;
	char	*num;

	sign = 0;
	digits_len = ft_numlen_dec(n);
	if (n < 0)
		sign = 1;
	num = (char *)malloc((digits_len + sign + 1) * sizeof(char));
	if (!num)
		return (NULL);
	num[digits_len + sign] = '\0';
	if (sign)
		num[0] = '-';
	while (digits_len > 0)
	{
		num[digits_len + sign - 1] = ft_int_to_ascii(n % 10);
		n = n / 10;
		digits_len--;
	}
	return (num);
}
