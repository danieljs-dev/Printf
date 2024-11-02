/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:59:40 by dajesus-          #+#    #+#             */
/*   Updated: 2024/11/02 06:55:54 by dajesus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAPPERS_H
# define WRAPPERS_H

# include <stdarg.h>

int	print_string(va_list args);
int	print_int(va_list args);
int	print_unsigned(va_list args);
int	print_char(va_list args);

#endif