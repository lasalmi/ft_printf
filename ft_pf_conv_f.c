/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_conv_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 06:13:44 by lasalmi           #+#    #+#             */
/*   Updated: 2022/04/14 12:41:56 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_pf_f_leading_zeroes(unsigned long long nb, t_strdata *strdata, \
char *str)
{
	size_t	len;
	int		diff;

	len = 0;
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	while (strdata->precision + 1 > 0)
	{
		str[strdata->precision-- + 1] = '0';
	}
}

static long long	ft_pf_power_of_ten(int power)
{
	long long	result;

	result = 1;
	while (power-- > 0)
		result *= 10;
	return (result);
}

static unsigned long long	ft_pf_round_f(t_strdata *strdata, long double nb)
{
	long long			remove;
	unsigned long long	result;
	long double			round;
	uint8_t				is_negative;

	is_negative = 0;
	if (nb < 0)
		nb *= -1;
	remove = nb;
	nb -= remove;
	result = (unsigned long long)(nb * ft_pf_power_of_ten(strdata->precision));
	return (result);
}

static void	ft_pf_convert_d_decimal(t_vardata *vardata, \
unsigned long long result, char *str, t_strdata *strdata)
{
	unsigned long long	for_zeroes;

	for_zeroes = result;
	str[strdata->precision-- + 1] = '\0';
	if (strdata->explicit_zeroprec && strdata->flags.alt_form)
	{
		str[0] = '.';
		return ;
	}
	while (result > 0 && (strdata->precision + 1) > 0)
	{
		str[strdata->precision-- + 1] = (result % 10) + '0';
		result /= 10;
	}
	ft_pf_f_leading_zeroes(for_zeroes, strdata, str);
	str[strdata->precision + 1] = '.';
}

static void	ft_pf_convert_f_int(t_vardata *vardata, long double nb, char *str)
{
	long long	result;
	size_t		i;

	i = (size_t)vardata->intlen;
	if (nb < 0)
		nb *= -1;
	result = (long long)nb;
	if (result == 0)
		str[--i] = '0';
	while (result > 0)
	{
		str[--i] = (result % 10) + '0';
		result /= 10;
	}
}

void	ft_pf_conv_f(t_vardata *vardata, t_strdata *strdata, \
long double nb, char *str)
{
	unsigned long long	frac;
	uint8_t				is_negative;

	frac = 0;
	if (nb < 0.0L)
	{
		nb *= -1;
		is_negative = 1;
	}
	ft_pf_convert_f_int(vardata, nb, str);
	nb -= (int)nb;
	frac = nb * ft_pf_power_of_ten(strdata->precision + 1);
	frac += 5;
	frac /= 10;
	ft_pf_convert_d_decimal(vardata, frac, str + vardata->intlen, strdata);
}
