/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:27:01 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/20 13:28:52 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Reads through the format string, if no output, sets the stage to end*/

t_status	ft_read_format(t_pf_controller *pf_controller, t_strdata *strdata)
{
	int			*i;
	t_status	ret;

	i = &pf_controller->format_i;
	ret = ft_check_character(strdata->working_format[*i]);
	while (ret == OKAY)
	{
		*i += 1;
		ret = ft_check_character(strdata->working_format[*i]);
		if (ret == NULLBYTE || ret == PERCENT)
		{
			ft_pf_set_stage_to(pf_controller, FT_WRITE);
			return (ret);
		}
	}
	if (ret == NULLBYTE)
		ft_pf_set_stage_to(pf_controller, FT_END);
	else
		ft_pf_set_stage_to(pf_controller, FT_READ_SPEC);
	return (ret);
}

/* Adds format_i to chars written and changes format_i to zero */
void	ft_pf_increase_written(t_pf_controller *pf_controller, t_strdata *strdata)
{
	strdata->working_format += pf_controller->format_i;
	pf_controller->chars_written += pf_controller->format_i;
	pf_controller->format_i = 0;
}

/*void	ft_pf_move_format_ptr(t_pf_controller *pf_controller, \
t_strdata *strdata)
{
	strdata->working_format += pf_controller->format_i;
} */

/* Writes to stdout already iterated literal, moves the pointer forward
and set the format_index to zero */
t_status	ft_write_iterated(t_pf_controller \
*pf_controller, t_strdata *strdata)
{
	t_status	ret;

	write(1, strdata->working_format, pf_controller->format_i);
/*	ft_pf_move_format_ptr(pf_controller, strdata); */
	ft_pf_increase_written(pf_controller, strdata);
	ret = ft_check_character(strdata->working_format[0]);
	if (ret == OKAY)
		exit(1);
	if (ret == NULLBYTE)
		ft_pf_set_stage_to(pf_controller, FT_END);
	else
		ft_pf_set_stage_to(pf_controller, FT_READ_SPEC);
	return (ret);
}

t_status	ft_check_character(const char c)
{
	if (c == '\0')
		return (NULLBYTE);
	if (c == '%')
		return (PERCENT);
	return (OKAY);
}

int	ft_printf(const char *input_format, ...)
{
	t_strdata		strdata;
	t_status		ret;
	t_pf_controller	pf_controller;

	ret = OKAY;
	va_start(strdata.list, input_format);
	strdata.working_format = input_format;
	ft_pf_init_pf_controller(&pf_controller);
	ft_pf_init_strdata(&strdata);
	while (pf_controller.stage != FT_END && pf_controller.stage != -1)
	{
		if (pf_controller.stage == FT_READ_PRINT)
			ft_read_format(&pf_controller, &strdata);
		if (pf_controller.stage == FT_WRITE)
			ft_write_iterated(&pf_controller, &strdata);
		if (pf_controller.stage == FT_CONVERT)
			ft_conv_handler(&pf_controller, &strdata);
		if (pf_controller.stage == FT_READ_SPEC)
			ft_pf_read_specifiers(&pf_controller, &strdata);
	}
	va_end(strdata.list);
	return (pf_controller.chars_written);
}
