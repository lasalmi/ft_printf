/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_check_zeropadding.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:41:08 by lasalmi           #+#    #+#             */
/*   Updated: 2022/03/23 15:50:47 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_pf_check_zeropadding(t_vardata *vardata, t_strdata *strdata)
{
	if (strdata->precision > vardata->conv_len)
	{
		vardata->zero_prec = (strdata->precision - vardata->conv_len);
		vardata->conv_len += vardata->zero_prec;
	}
	else if (strdata->flags.pad_with_zeroes == 1 && strdata->width > vardata->conv_len)
	{
		vardata->zero_prec = vardata->padlen;
		vardata->conv_len += vardata->zero_prec;
		strdata->strlen = vardata->conv_len;
		vardata->padlen = 0;
		strdata->flags.pad_with_zeroes = 0;
	}

}