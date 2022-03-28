/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_get_uint_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:57:24 by lasalmi           #+#    #+#             */
/*   Updated: 2022/03/28 16:57:45 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pf_get_conv_base(t_strdata *strdata)
{
	if (strdata->working_format[-1] == 'x')
		return (16);
	if (strdata->working_format[-1] == 'o')
		return (8);
	if (strdata->working_format[-1] == 'X')
		return (16);
	if (strdata->working_format[-1] == 'u')
		return (10);
	return (10);
}

void	ft_add_zeropad(char **str, size_t padlen)
{
	size_t	i;

	i = 0;
	
	while (padlen > 0)
	{
		str[0][i]= '0';
		i++;
		padlen--;
	}
	*str += i;
}

void	ft_pf_add_0x(char **str)
{
	str[0][0] = '0';
	str[0][1] = 'x';
	*str += 2;
}
/*!REVISIT STRLEN/INTLEN!5Conv_len total space required for uint conversion result str without \0 
intlen for starting index for conversion, padlen to know how many pads
and same for zero_prec */
void	ft_pf_get_uint_data(t_vardata *vardata, unsigned long long nb, int base, t_strdata *strdata)
{

	vardata->zero_prec = 0;
	vardata->conv_len = 0;
	vardata->padlen = 0;
	if (nb == 0)
		vardata->conv_len = 1;
	while (nb > 0)
	{
		nb /= base;
		vardata->conv_len++;
	}
	vardata->intlen = vardata->conv_len;
//	strdata->strlen = vardata->intlen;
//	ft_pf_check_zeropadding(vardata, strdata);
//	if (strdata->precision > vardata->conv_len)
//	{
//		vardata->zero_prec = (strdata->precision - vardata->conv_len);
//		vardata->conv_len += vardata->zero_prec; 
//	}
	if (strdata->flags.alt_form == 1)
		vardata->conv_len += 2;
	if (vardata->conv_len < strdata->width)
	{
		vardata->padlen = (strdata->width - vardata->conv_len);
//		vardata->conv_len += vardata->padlen;
	}
	ft_pf_check_zeropadding(vardata, strdata);
}