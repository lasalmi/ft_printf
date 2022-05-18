/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:05:12 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/18 15:13:44 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_output_error(t_pf_controller *ft_controller, t_strdata *strdata)
{
	ft_controller->chars_written = -1;
	free(strdata->variable_str);
	strdata->variable_str = NULL;
	free(strdata->padding);
	strdata->padding = NULL;
	ft_controller->stage = FT_END;
	return (1);
}

static void	ft_pf_print_padding(t_pf_controller *ft_controller, \
t_strdata *strdata)
{
	int	ret;

	ret = 0;
	if (!strdata->padding || ft_controller->stage == FT_END)
		return ;
	ret = write(1, strdata->padding, strdata->padlen);
	if (ret < 0 && ft_output_error(ft_controller, strdata))
		return ;
	ft_controller->chars_written += strdata->padlen;
	strdata->padlen = 0;
	free(strdata->padding);
	strdata->padding = NULL;
}

static void	ft_pf_print_variable(t_pf_controller *ft_controller, \
t_strdata *strdata)
{
	int	ret;

	ret = 0;
	if (!strdata->variable_str || ft_controller->stage == FT_END)
		return ;
	ret = write(1, strdata->variable_str, strdata->strlen);
	if (ret < 0 && ft_output_error(ft_controller, strdata))
		return ;
	ft_controller->chars_written += strdata->strlen;
	strdata->strlen = 0;
	free(strdata->variable_str);
	strdata->variable_str = NULL;
}

/* Prints the generated strings, frees the memory and adds written chars */
void	ft_pf_print(t_pf_controller *ft_controller, t_strdata *strdata)
{
	t_flags	*flags;

	flags = &strdata->flags;
	if (flags->padleft)
		ft_pf_print_variable(ft_controller, strdata);
	ft_pf_print_padding(ft_controller, strdata);
	ft_pf_print_variable(ft_controller, strdata);
	if (ft_controller->stage == FT_END)
		return ;
	ft_pf_init_strdata(strdata);
	ft_controller->stage = FT_READ_PRINT;
}
