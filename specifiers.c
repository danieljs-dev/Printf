/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:04:21 by dajesus-          #+#    #+#             */
/*   Updated: 2024/11/02 08:04:50 by dajesus-         ###   ########.fr       */
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
	static const t_specifier	specifiers[6] = {
	{'s', print_string},
	{'d', print_int},
	{'i', print_int},
	{'u', print_unsigned},
	{'c', print_char},
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
