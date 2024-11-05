/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:38:43 by dajesus-          #+#    #+#             */
/*   Updated: 2024/11/04 21:25:16 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "wrappers.h"
# include "./libft/libft.h"

# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

typedef int	(*t_print_func)(va_list);

typedef struct s_specifier {
	char			specifier;
	t_print_func	func;
}					t_specifier;

int				ft_printf(const char *str, ...);
t_print_func	find_function(char specifier);

#endif