/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_ouxX_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:57:13 by lasalmi           #+#    #+#             */
/*   Updated: 2022/03/26 12:51:12 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf2/ft_printf.h"
static void ft_pf_uoxX_toupper(t_strdata *strdata)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = strdata->variable_str;
	while (ptr[i] != '\0')
	{
		ptr[i] = ft_toupper(ptr[i]);
		i++;
	}
}
static void ft_pf_uoxX_padding(t_strdata *strdata, t_vardata vardata)
{
	t_status	ret;
	strdata->padlen = vardata.padlen;
	ret = ft_pf_pad_with(strdata, ' ');
	if (ret != OKAY)
		exit(1);
}
static unsigned long long ft_pf_fetch_ouxX_var(t_strdata *strdata)
{
	t_length len;

	len = strdata->flags.length;
	if (len == PF_HH || len == PF_H)
		return ((unsigned long long)va_arg(strdata->list, unsigned int));
	if (len == PF_LL)
		return (va_arg(strdata->list, unsigned long long));
	if (len == PF_L)
		return ((unsigned long long)va_arg(strdata->list, unsigned long));
	return ((unsigned long long)va_arg(strdata->list, unsigned int));
}

static void ft_pf_check_ouxX_flags(t_strdata *strdata)
{
	if (strdata->precision > 0 || strdata->flags.padleft == 1)
		strdata->flags.pad_with_zeroes = 0;
}

void	ft_pf_ouxX_handler(t_ft_controller *ft_controller, t_strdata *strdata)
{
	t_vardata			vardata;
	unsigned long long 	var;
	char				*ptr;

	var = ft_pf_fetch_ouxX_var(strdata);
	ft_pf_check_ouxX_flags(strdata);
	ft_pf_get_uint_data(&vardata, var, ft_pf_get_conv_base(strdata), strdata);
	strdata->variable_str = (char *)malloc(vardata.conv_len + 1);
	strdata->strlen = vardata.conv_len; 
	if (!strdata->variable_str)
		exit(1);
	ptr = strdata->variable_str;
	if (strdata->flags.alt_form)
		ft_pf_add_0x(&ptr);
	if (vardata.zero_prec > 0)
		ft_add_zeropad(&ptr, vardata.zero_prec);
	if (strdata->flags.pad_with_zeroes == 1)
		ft_add_zeropad(&ptr, vardata.padlen);
	ft_conv_ouxX(var, ft_pf_get_conv_base(strdata), vardata.intlen, ptr);
	if (!strdata->flags.pad_with_zeroes && vardata.padlen)
		ft_pf_uoxX_padding(strdata, vardata);
//	strdata->strlen = vardata.conv_len; 
	if (strdata->working_format[-1] == 'X')
		ft_pf_uoxX_toupper(strdata);
	ft_pf_print(ft_controller, strdata);
}