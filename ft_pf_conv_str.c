/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_conv_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:05:32 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/18 15:16:15 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_pf_str_precision(t_strdata *strdata, char *str)
{
	int		i;
	size_t	strlen;

	strlen = strdata->precision;
	i = 0;
	strdata->variable_str = (char *)malloc(strlen + 1);
	while (i < strdata->precision)
	{
		strdata->variable_str[i] = str[i];
		i++;
	}
	strdata->variable_str[i] = '\0';
	strdata->strlen = strdata->precision;
}

t_status	ft_pf_conv_str(t_pf_controller *pf_controller, \
t_strdata *strdata, char *str)
{
	size_t				strlen;
	t_status			ret;
	static const char	null_str[] = "(null)";

	ret = OKAY;
	if (!str)
		str = null_str;
	strlen = ft_strlen(str);
	if ((!strdata->precision && !strdata->explicit_zeroprec) \
	|| strlen < strdata->precision)
	{
		strlen = ft_strlen(str);
		strdata->strlen = strlen;
		strdata->variable_str = ft_strdup(str);
	}
	else
		ft_pf_str_precision(strdata, str);
	if (!strdata->variable_str)
		ret = MALLOCFAIL;
	return (ret);
}
