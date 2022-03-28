/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:05:12 by lasalmi           #+#    #+#             */
/*   Updated: 2022/03/22 19:30:05 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_pf_print_padding(t_ft_controller *ft_controller, t_strdata *strdata)
{
	if (!strdata->padding)
		return ;
	write(1, strdata->padding, strdata->padlen);
	ft_controller->chars_written += strdata->padlen;
	strdata->padlen = 0;
	free(strdata->padding);
	strdata->padding = NULL;
}

static void	ft_pf_print_variable(t_ft_controller *ft_controller, t_strdata *strdata)
{
	if (!strdata->variable_str)
		return ;
	write(1, strdata->variable_str, strdata->strlen);
	ft_controller->chars_written += strdata->strlen;
	strdata->strlen = 0;
	free(strdata->variable_str);
	strdata->variable_str = NULL;
}
/* Prints the generated strings, frees the memory and adds written chars */
void	ft_pf_print(t_ft_controller *ft_controller, t_strdata *strdata)
{
	t_flags *flags;

	flags = &strdata->flags;
	if (flags->padleft)
		ft_pf_print_variable(ft_controller, strdata);
	ft_pf_print_padding(ft_controller, strdata);
	ft_pf_print_variable(ft_controller, strdata);
	ft_init_strdata(strdata);
	ft_controller->stage = FT_READ_PRINT;
}
