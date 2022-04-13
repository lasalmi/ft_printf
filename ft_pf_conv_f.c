/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_conv_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 06:13:44 by lasalmi           #+#    #+#             */
/*   Updated: 2022/04/11 12:32:51 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void ft_pf_convert_d_decimal(t_vardata *vardata, long double nb, char *str, t_strdata *strdata)
{
	long double round;
	long long	result;
	long long	remove;

	if (nb < 0)
		nb *= -1;
	remove = (long long)nb;
	round = 5.00 / (10000000.00);
	nb += round;
	nb -= remove;
/* KORJAA PRECISION! */
	result = (long long)(nb * 1000000);
	str[strdata->precision-- + 1] = '\0';
	if (strdata->precision == 0 && strdata->flags.alt_form)
	{
		str[0] = '.';
		return ;
	}
	while (result > 0 && (strdata->precision + 1) > 0)
	{
		str[strdata->precision-- + 1] = (result % 10) + '0';
		result /= 10;
	}
	str[strdata->precision + 1] = '.';
}
/* Tähän nollacase handlaus */
static	void ft_pf_convert_f_int(t_vardata *vardata, long double nb, char *str)
{
	long long 	result;
	size_t		i;

	i = (size_t)vardata->intlen;
	if (nb < 0)
		nb *= -1;
	result = (long long)nb;
	while (result > 0)
	{
		str[--i] = (result % 10) + '0';
		result /= 10;
	}
}

void ft_pf_conv_f(t_vardata *vardata, t_strdata *strdata, long double nb, char *str)
{
	ft_pf_convert_f_int(vardata, nb, str);
	ft_pf_convert_d_decimal(vardata, nb, str + vardata->intlen, strdata);
}