/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:29:10 by lasalmi           #+#    #+#             */
/*   Updated: 2022/03/19 22:53:23 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include <stdio.h>

typedef struct s_flags
{
	uint8_t		padleft;
	uint8_t		sign;
	uint8_t		space;
	uint8_t		pad_with_zeroes;
}	t_flags;

typedef enum e_ft_stage
{
	FT_READ_PRINT,
	FT_READ_SPEC,
	FT_CONV_CHAR,
	FT_CONV_STR,
	FT_CONV_PTR,
	FT_PAD,
	FT_WRITE,
	FT_END,
	___UNUSED
} t_stage;

typedef struct s_strdata
{
	t_flags	flags;
	int		width;
	int		precision;
	uint8_t	conversion;
	char	*variable_str;
	char	*padding;
	const char	*working_format;
	va_list list;
}	t_strdata;

typedef struct s_ft_controller
{
	t_stage stage;
	int		chars_written;
	int		format_i;
	char	*to_print;
//	t_status last_status;
}	t_ft_controller;

typedef enum e_status
{
	OKAY,
	MALLOCFAIL,
	WRITE,
	NULLBYTE,
	PERCENT,
	_UNUSED
}	t_status;

/*typedef enum e_conversion
{
	CHAR,
	STRING,
	POINTER,
	__UNUSED
}	t_conversion; */
int	ft_printf(const char *input_format, ...);
void	ft_printf_read_specifiers(t_strdata *current_variable);
t_status ft_printf_percent(t_strdata *data);
void ft_pf_stage_to_write(t_ft_controller *ft_controller);
void ft_pf_stage_to_end(t_ft_controller *ft_controller);
void ft_pf_stage_to_read_spec(t_ft_controller *ft_controller);
t_status ft_check_character(char c);
#endif