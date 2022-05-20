/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 00:16:20 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/21 00:34:26 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	ft_dprintf(int fd, const char *input_format, ...)
{
	t_strdata		strdata;
	t_status		ret;
	t_pf_controller	pf_controller;

	ret = OKAY;
	va_start(strdata.list, input_format);
	strdata.working_format = input_format;
	ft_pf_init_pf_controller(&pf_controller);
	ft_pf_init_strdata(&strdata);
	pf_controller.caller = FT_DPRINTF;
	pf_controller.fd = fd;
	while (pf_controller.stage != FT_END && pf_controller.stage != -1)
	{
		g_funcs[pf_controller.stage](&pf_controller, &strdata);
	}
	va_end(strdata.list);
	return (pf_controller.chars_written);
}