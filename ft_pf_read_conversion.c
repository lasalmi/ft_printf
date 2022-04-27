/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_read_conversion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:19:34 by lasalmi           #+#    #+#             */
/*   Updated: 2022/04/27 16:17:34 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* We will convert whatever char it is and use
is as a char input in our char converter */
int	ft_pf_check_if_ouxx(t_strdata *strdata)
{
	if (strdata->working_format[-1] == 'o')
		return (1);
	if (strdata->working_format[-1] == 'u')
		return (1);
	if (strdata->working_format[-1] == 'x')
		return (1);
	if (strdata->working_format[-1] == 'X')
		return (1);
	return (0);
}

t_stage	ft_read_conversion(t_strdata *strdata)
{
	strdata->working_format += 1;
	if (strdata->working_format[-1] == 'c')
		return (FT_CONV_CHAR);
	if (strdata->working_format[-1] == 'f')
		return (FT_CONV_FLOAT);
	if (strdata->working_format[-1] == 's')
		return (FT_CONV_STR);
	if (strdata->working_format[-1] == 'p')
		return (FT_CONV_PTR);
	if (ft_pf_check_if_ouxx(strdata))
		return (FT_conv_oux);
	if (strdata->working_format[-1] == 'd' \
	|| strdata->working_format[-1] == 'i')
		return (FT_CONV_DI);
	return (FT_CONV_CHAR);
}
