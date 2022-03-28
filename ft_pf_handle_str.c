/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:15:21 by lasalmi           #+#    #+#             */
/*   Updated: 2022/03/21 16:26:41 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* Sets the ignored flags for char to zero */
void ft_pf_validate_str_flags(t_strdata *strdata)
{
	t_flags	*flags;

	flags = &strdata->flags;
	if (flags->padleft == 1)
		flags->pad_with_zeroes = 0;
	flags->space = 0;
	flags->sign = 0;
}
t_status ft_pf_handle_str_width(t_strdata *strdata)
{
	t_status	ret;

	ret = OKAY;
	if (strdata->width > strdata->strlen)
	{
		if (strdata->flags.padleft)
			ret = ft_pf_pad_with(strdata, ' ');
		else if (strdata->flags.pad_with_zeroes)
			ret = ft_pf_pad_with(strdata, '0');
		else
			ret = ft_pf_pad_with(strdata, ' ');
	}
	return (ret);
}
void ft_pf_handle_str(t_ft_controller *ft_controller, t_strdata *strdata)
{
	t_status ret;

	ft_pf_validate_str_flags(strdata);
	ret = ft_pf_conv_str(ft_controller, strdata, va_arg(strdata->list, void*));
	if (ret != OKAY)
		exit(1); /* Revisit this! */
	ret = ft_pf_handle_str_width(strdata);
	if (ret != OKAY)
		exit(1); /* Revisit this! */
	ft_pf_print(ft_controller, strdata);
}