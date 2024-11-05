/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:59:40 by dajesus-          #+#    #+#             */
/*   Updated: 2024/11/04 22:17:39 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAPPERS_H
# define WRAPPERS_H

# include <stdarg.h>

int	print_char(va_list args);
int	print_string(va_list args);
int	print_pointer(va_list args);
int	print_int(va_list args);
int	print_unsigned_dec(va_list args);
int	print_unsigned_lower_hex(va_list args);
int	print_unsigned_upper_hex(va_list args);

#endif