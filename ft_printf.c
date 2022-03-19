/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:27:01 by lasalmi           #+#    #+#             */
/*   Updated: 2022/03/20 00:15:52 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Reads through the format string, if no output, sets the stage to end*/
t_status	ft_read_format(t_ft_controller *ft_controller, t_strdata *strdata)
{
	int			*i;
	t_status	ret;

	i = &ft_controller->format_i;
	ret = ft_check_character(strdata->working_format[*i]);
	while (ret == OKAY)
	{
		*i += 1;
		ret = ft_check_character(strdata->working_format[*i]);
		if (ret == NULLBYTE || ret == PERCENT)
		{
			ft_pf_stage_to(ft_controller, FT_WRITE);
			return (ret);
		}
	}
	ft_pf_stage_to(ft_controller, FT_END);
	return (ret);
}

/* Adds format_i to chars written and changes format_i to zero */
void	ft_pf_increase_written(t_ft_controller *ft_controller)
{
	ft_controller->chars_written += ft_controller->format_i;
	ft_controller->format_i = 0;
}

void	ft_pf_move_format_ptr(t_ft_controller *ft_controller, t_strdata *strdata)
{
	strdata->working_format += ft_controller->format_i;
}

/* Writes to stdout already iterated literal, moves the pointer forward
and set the format_index to zero */
t_status ft_write_iterated(t_ft_controller *ft_controller, t_strdata *strdata)
{
	t_status ret;
	write(1, strdata->working_format, ft_controller->format_i);
	ft_pf_move_format_ptr(ft_controller, strdata);
	ft_pf_increase_written(ft_controller);
	ret = ft_check_character(strdata->working_format[0]);
	if (ret == OKAY)
	{
		ft_putstr("ERROR!");
		exit(1);
	}
	if (ret == NULLBYTE)
		ft_pf_stage_to(ft_controller, FT_END);
	else
		ft_pf_stage_to(ft_controller, FT_READ_SPEC);
	return (ret);
}

t_status ft_check_character(const char c)
{
	if (c == '\0')
		return (NULLBYTE);
	if (c == '%')
		return (PERCENT);
	return (OKAY);
}

static void ft_init_flags(t_flags *flags_to_init)
{
	flags_to_init->padleft = 0;
	flags_to_init->padleft = 0;
	flags_to_init->sign = 0;
	flags_to_init->pad_with_zeroes = 0;
}

static void	ft_init_strdata(t_strdata *data_to_init, const char *input_format)
{
	ft_init_flags(&data_to_init->flags);
	data_to_init->width = 0;
	data_to_init->precision = 0;
	data_to_init->conversion = 0;
	data_to_init->variable_str = NULL;
	data_to_init->padding = NULL;
	data_to_init->working_format = input_format;
}

static void ft_init_ft_controller(t_ft_controller *ft_controller)
{
	ft_controller->stage = FT_READ_PRINT;
	ft_controller->chars_written = 0;
	ft_controller->to_print = NULL;
	ft_controller->format_i = 0;
//	ft_controller->last_status = OKAY;
}

int	ft_printf(const char *input_format, ...)
{
	t_strdata strdata;
	t_status ret;
	t_ft_controller ft_controller;
	ret = OKAY;

	va_start(strdata.list, input_format);
	ft_init_ft_controller(&ft_controller);
	ft_init_strdata(&strdata, input_format);
	while (ft_controller.stage != FT_END)
	{
		if (ft_controller.stage == FT_READ_PRINT)
			ret = ft_read_format(&ft_controller, &strdata);
		if (ft_controller.stage == FT_WRITE)
			ret = ft_write_iterated(&ft_controller, &strdata);
	}
	return (ft_controller.chars_written);
}
