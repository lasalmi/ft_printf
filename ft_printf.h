/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:29:10 by lasalmi           #+#    #+#             */
/*   Updated: 2022/03/28 18:54:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

typedef enum e_length
{
	PF_HH,
	PF_H,
	PF_L,
	PF_LL,
}	t_length;
typedef struct s_flags
{
	int		padleft;
	int		sign;
	int		space;
	int		pad_with_zeroes;
	int		alt_form;
	t_length	length;
}	t_flags;

typedef enum e_ft_stage
{
	FT_READ_PRINT,
	FT_READ_SPEC,
	FT_CONVERT,
	FT_CONV_CHAR,
	FT_CONV_STR,
	FT_CONV_PTR,
	FT_CONV_OUXX,
	FT_CONV_DI,
	FT_PAD,
	FT_WRITE,
	FT_END,
	___UNUSED
} t_stage;

typedef	struct s_vardata
{
	size_t	padlen;
	size_t	conv_len;
	size_t	zero_prec;
	uint8_t	toupper;
	size_t	intlen;
}	t_vardata;

typedef struct s_strdata
{
	t_flags	flags;
	int		width;
	int		precision;
	uint8_t	length;
	uint8_t	conversion;
	char	*variable_str;
	int		strlen;
	char	*padding;
	int		padlen;
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
	ERROR,
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
void ft_pf_stage_to_write(t_ft_controller *ft_controller);
void ft_pf_stage_to_end(t_ft_controller *ft_controller);
void ft_pf_stage_to_read_spec(t_ft_controller *ft_controller);
t_status ft_check_character(char c);
t_status ft_pf_conv_char(t_ft_controller *ft_controller, t_strdata *strdata,
int c);
t_status ft_pf_conv_str(t_ft_controller *ft_controller, t_strdata *strdata,
char *str);
t_stage ft_read_conversion(t_strdata *strdata);
void	ft_pf_print(t_ft_controller *ft_controller, t_strdata *strdata);
void ft_pf_handle_char(t_ft_controller *ft_controller, t_strdata *strdata);
void ft_pf_set_stage_to(t_ft_controller *ft_controller, t_stage to);
t_status	ft_pf_pad_with(t_strdata *strdata, char c);
void	ft_conv_handler(t_ft_controller *ft_controller, t_strdata *strdata);
void	ft_pf_read_specifiers(t_ft_controller *ft_controller, t_strdata *strdata);
void	ft_pf_handle_str(t_ft_controller *ft_controller, t_strdata *strdata);
void	ft_pf_handle_ptr(t_ft_controller *ft_controller, t_strdata *strdata);
t_status ft_pf_convert_hexa(t_ft_controller *ft_controller, t_strdata *strdata, long long ptr);
void	ft_init_strdata(t_strdata *data_to_init);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int		ft_toupper(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_isdigit(int c);
void	ft_pf_ouxX_handler(t_ft_controller *ft_controller, t_strdata *strdata);
void 	ft_conv_ouxX(unsigned long long nb, int base, size_t intlen, char *str);
void	ft_pf_get_uint_data(t_vardata *vardata, unsigned long long nb, int base, t_strdata *strdata);
int		ft_pf_get_conv_base(t_strdata *strdata);
void	ft_add_zeropad(char **str, size_t padlen);
void	ft_pf_add_0x(char **str);
int		ft_strnequ(const char *s1, const char *s2, size_t n);
void	ft_pf_read_length(t_strdata *strdata);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void ft_pf_check_zeropadding(t_vardata *vardata, t_strdata *strdata);
void	ft_pf_get_sint_len(t_vardata *vardata, long long nb, t_strdata *strdata);
void	ft_pf_handle_di(t_ft_controller *ft_controller, t_strdata *strdata);
void	ft_conv_di(long long nb, int base, size_t intlen, char *str);
void	ft_pf_uoxX_padding(t_strdata *strdata, t_vardata vardata);
#endif
