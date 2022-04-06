/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_get_double_len.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:10:36 by lasalmi           #+#    #+#             */
/*   Updated: 2022/03/31 09:42:52 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_pf_check_double(t_vardata *vardata, long long nb, t_strdata *strdata)
{
	if (strdata->precision = 0 && !strdata->flags.alt_form && nb >= 0)
		return ;
	if (strdata->flags.sign || strdata->flags.space)
		if (nb > 0)
			vardata->conv_len += 1;
	if (nb < 0)
		vardata->conv_len += 1;
	vardata->conv_len += strdata->precision + 1;
}

void	ft_pf_get_double_len(t_vardata *vardata, long double nb, t_strdata *strdata)
{
	long long	firstpart;
	size_t		
	firstpart = (long long)nb;
	vardata->zero_prec = 0;
	vardata->conv_len = 0;
	vardata->padlen = 0;
	if (firstpart < 0)
		firstpart *= -1;
	while (firstpart > 0)
	{
		firstpart /= 10;
		vardata->conv_len += 1;
	}
	vardata->intlen = vardata->conv_len;
	ft_pf_check_double(vardata, (long long)nb, strdata);
	if (strdata->width > vardata->conv_len)
		vardata->padlen = vardata->conv_len - strdata->width;
	if (strdata->flags.pad_with_zeroes && vardata->padlen)
		vardata->conv_len += vardata->padlen;
}