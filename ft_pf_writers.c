/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_writers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:17:37 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/24 15:47:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_sprintf(t_pf_controller *pf_controller, char *to_print, size_t len)
{
	if (len + pf_controller->chars_written + 1 < pf_controller->size)
		ft_memcpy(pf_controller->temp_print, to_print, len);
	else
	{
		len = pf_controller->size - pf_controller->chars_written - 1;
		ft_memcpy(pf_controller->temp_print, to_print, len);
	}
	pf_controller->temp_print += len;
	return (1);
}

int	ft_pf_writer(t_pf_controller *pf_controller, char *to_print, size_t len)
{
	t_pf_caller	caller;
	int			ret;

	caller = pf_controller->caller;
	if(caller < 2)
		ret = write(pf_controller->fd, to_print, len);
	else if (caller == FT_SPRINTF)
		ret = ft_write_sprintf(pf_controller, to_print, len);
	return (ret);
}