/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:04:21 by dajesus-          #+#    #+#             */
/*   Updated: 2024/11/04 22:17:46 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static t_specifier	*create_specifiers(void)
{
	static t_specifier		specifiers[3];

	specifiers[0] = (t_specifier){'s', print_string};
	specifiers[1] = (t_specifier){'d', print_int};
	specifiers[2] = (t_specifier){'\0', NULL};
	return (specifiers);
}*/

t_print_func	find_function(char specifier)
{
	int							i;
	static const t_specifier	specifiers[9] = {
	{'c', print_char},
	{'s', print_string},
	{'p', print_pointer},
	{'d', print_int},
	{'i', print_int},
	{'u', print_unsigned_dec},
	{'x', print_unsigned_lower_hex},
	{'X', print_unsigned_upper_hex},
	{'\0', NULL}
	};
	//t_specifier					*specifiers;

	i = 0;
	//specifiers = create_specifiers();
	while (specifiers[i].specifier != '\0')
	{
		if (specifiers[i].specifier == specifier)
			return (specifiers[i].func);
		i++;
	}
	return (NULL);
}
