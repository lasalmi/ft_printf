/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_get_int_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:05:29 by lasalmi           #+#    #+#             */
/*   Updated: 2022/03/28 17:14:18 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_sign (t_vardata *vardata, long long nb, t_strdata *strdata)
{
	if (strdata->flags.sign || strdata->flags.space)
		if (nb > 0)
			vardata->conv_len += 1;
	if (nb < 0)
		vardata->conv_len += 1;
}
void	ft_pf_get_sint_len(t_vardata *vardata, long long nb, t_strdata *strdata)
{
	vardata->zero_prec = 0;
	vardata->conv_len = 0;
	vardata->padlen = 0;
	if (nb < 0)
		nb *= 1;
	while (nb > 0)
	{
		nb /= 10;
		vardata->conv_len += 1;
	}
	vardata->intlen = vardata->conv_len;
	ft_check_sign(vardata, nb, strdata); /* Check this */
	if (strdata->width > vardata->conv_len)
		vardata->padlen = strdata->width - vardata->conv_len;
	ft_pf_check_zeropadding(vardata, strdata);
}
