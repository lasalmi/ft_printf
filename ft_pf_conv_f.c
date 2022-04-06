/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_conv_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 06:13:44 by lasalmi           #+#    #+#             */
/*   Updated: 2022/04/06 15:08:45 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void ft_pf_convert_d_decimal(t_vardata *vardata, long double nb, char *str, t_strdata *strdata)
{
	long double round;
	long long	result;

	round = 5 / (10 * strdata->precision + 1);
	nb += round;
	nb -= (long long)nb;
	result = (long long)(nb * (10 * strdata->precision));
/*	if (strdata->precision == 0) Tähän check että onko alt form eli . vaikka prec 0 ja return.
		ft_pf_check_dec_point() */
	while (result > 0)
	{
		str[--strdata->precision] = result % 10;
		result / 10;
	}
	str[--strdata->precision] = '.';
}
/* Tähän nollacase handlaus */
static	void ft_pf_convert_f_int(t_vardata *vardata, long double nb, char *str)
{
	long long 	result;
	size_t		i;

	i = (size_t)vardata->intlen;
	result = (long long)nb;
	while (result > 0)
	{
		str[i--] = result % 10;
		result /= 10;
	}
}

void ft_pf_conv_f(t_vardata *vardata, t_strdata *strdata, long double nb, char *str)
{
	ft_pf_convert_f_int(vardata, nb, strdata->variable_str);
	ft_pf_convert_d_decimal(vardata, nb, strdata->variable_str + vardata->intlen, strdata);
}