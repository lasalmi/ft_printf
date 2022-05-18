/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_initializers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:48:08 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/12 15:51:51 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_init_vardata(t_vardata *vardata)
{
	vardata->zero_prec = 0;
	vardata->conv_len = 0;
	vardata->padlen = 0;
}

void	ft_pf_init_flags(t_flags *flags_to_init)
{
	flags_to_init->space = 0;
	flags_to_init->padleft = 0;
	flags_to_init->sign = 0;
	flags_to_init->pad_with_zeroes = 0;
	flags_to_init->alt_form = 0;
	flags_to_init->length = PF_INIT;
}

void	ft_pf_init_strdata(t_strdata *data_to_init)
{
	ft_pf_init_flags(&data_to_init->flags);
	data_to_init->width = 0;
	data_to_init->precision = 0;
	data_to_init->explicit_zeroprec = 0;
	data_to_init->variable_str = NULL;
	data_to_init->padding = NULL;
}

void	ft_pf_init_ft_controller(t_ft_controller *ft_controller)
{
	ft_controller->stage = FT_READ_PRINT;
	ft_controller->chars_written = 0;
	ft_controller->to_print = NULL;
	ft_controller->format_i = 0;
}