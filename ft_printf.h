/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:29:10 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/20 14:00:40 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"

typedef enum e_length
{
	PF_INIT,
	PF_HH,
	PF_H,
	PF_L,
	PF_LL,
	PF_LONGD
}	t_length;
typedef struct s_flags
{
	int			padleft;
	int			sign;
	int			space;
	int			pad_with_zeroes;
	int			alt_form;
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
	FT_conv_oux,
	FT_CONV_DI,
	FT_CONV_FLOAT,
	FT_PAD,
	FT_WRITE,
	FT_END,
	___UNUSED
}	t_stage;

typedef struct s_vardata
{
	size_t	padlen;
	size_t	conv_len;
	size_t	zero_prec;
	uint8_t	toupper;
	size_t	intlen;
}	t_vardata;

typedef struct s_strdata
{
	t_flags		flags;
	int			width;
	int			precision;
	uint8_t		length;
	uint8_t		explicit_zeroprec;
	char		*variable_str;
	int			strlen;
	char		*padding;
	int			padlen;
	const char	*working_format;
	va_list		list;
}	t_strdata;

typedef struct s_pf_controller
{
	t_stage	stage;
	int		chars_written;
	int		format_i;
	char	*to_print;
}	t_pf_controller;

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

int			ft_printf(const char *input_format, ...);
void		ft_pf_stage_to_write(t_pf_controller *pf_controller);
void		ft_pf_stage_to_end(t_pf_controller *pf_controller);
void		ft_pf_stage_to_read_spec(t_pf_controller *pf_controller);
t_status	ft_check_character(char c);
t_status	ft_pf_conv_char(t_pf_controller *pf_controller, t_strdata *strdata, \
	int c);
t_status	ft_pf_conv_str(t_pf_controller *pf_controller, t_strdata *strdata, \
	char *str);
t_stage		ft_pf_read_conv(t_strdata *strdata);
void		ft_pf_print(t_pf_controller *pf_controller, t_strdata *strdata);
void		ft_pf_handle_char(t_pf_controller *pf_controller, \
t_strdata *strdata);
void		ft_pf_set_stage_to(t_pf_controller *pf_controller, t_stage to);
t_status	ft_pf_pad_with(t_strdata *strdata, char c);
void		ft_conv_handler(t_pf_controller *pf_controller, \
t_strdata *strdata);
void		ft_pf_read_specifiers(t_pf_controller *pf_controller, \
t_strdata *strdata);
void		ft_pf_handle_str(t_pf_controller *pf_controller, \
t_strdata *strdata);
void		ft_pf_handle_ptr(t_pf_controller *pf_controller, \
t_strdata *strdata);
t_status	ft_pf_convert_hexa(t_pf_controller *pf_controller, \
t_strdata *strdata, long long ptr);
void		ft_pf_init_strdata(t_strdata *data_to_init);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
int			ft_toupper(int c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_isdigit(int c);
void		ft_pf_oux_handler(t_pf_controller *pf_controller, \
t_strdata *strdata);
void		ft_conv_oux(unsigned long long nb, \
int base, size_t intlen, char *str);
void		ft_pf_get_uint_data(t_vardata *vardata, \
unsigned long long nb, int base, t_strdata *strdata);
int			ft_pf_get_conv_base(t_strdata *strdata);
void		ft_add_zeropad(char **str, size_t padlen);
void		ft_pf_add_0x(char **str, long long var, t_strdata *strdata);
int			ft_strnequ(const char *s1, const char *s2, size_t n);
void		ft_pf_read_length(t_strdata *strdata);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_pf_check_zeropadding(t_vardata *vardata, t_strdata *strdata);
void		ft_pf_get_sint_len(t_vardata *vardata, \
long long nb, t_strdata *strdata);
void		ft_pf_handle_di(t_pf_controller *pf_controller, t_strdata *strdata);
void		ft_conv_di(long long nb, int base, size_t intlen, char *str);
void		ft_pf_uox_padding(t_strdata *strdata, \
t_vardata vardata);
void		ft_pf_skip_leading_zeroes(char **str);
void		ft_pf_get_double_len(t_vardata *vardata, \
long double nb, t_strdata *strdata);
void		ft_pf_conv_f(t_vardata *vardata, \
t_strdata *strdata, long double nb, char *str);
void		ft_pf_handle_f(t_pf_controller *pf_controller, t_strdata *strdata);
void		ft_pf_round_f_str(char **str, t_strdata *strdata, \
size_t i, double nb);
int			ft_pf_need_upround(double d, int precision);
void		ft_pf_init_pf_controller(t_pf_controller *pf_controller);
void		ft_pf_init_strdata(t_strdata *data_to_init);
void		ft_pf_init_flags(t_flags *flags_to_init);
void		ft_pf_init_vardata(t_vardata *vardata);
#endif	
