/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:29:10 by lasalmi           #+#    #+#             */
/*   Updated: 2022/03/19 14:32:21 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
#include <stdlib.h>

typedef struct s_flags
{
	uint8_t		padleft;
	uint8_t		sign;
	uint8_t		space;
	uint8_t		pad_with_zeroes;
}	t_flags;

typedef struct s_strdata
{
	t_flags	flags;
	int		width;
	int		precision;
	uint8_t	conversion;
	char	*str;
	char	*padding;
	va_list list;
}	t_strdata;

#endif