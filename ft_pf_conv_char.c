/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_conv_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:46:03 by lasalmi           #+#    #+#             */
/*   Updated: 2022/04/14 12:35:40 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	ft_pf_conv_char(t_ft_controller *ft_controller, t_strdata *strdata, \
int c)
{
	if (strdata->variable_str != NULL)
		return (ERROR);
	strdata->variable_str = (char *)malloc(2);
	if (strdata->variable_str == NULL)
		return (MALLOCFAIL);
	strdata->variable_str[0] = c;
	strdata->variable_str[1] = '\0';
	strdata->strlen = 1;
	return (OKAY);
}
