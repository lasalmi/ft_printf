/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_conv_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:26:56 by lasalmi           #+#    #+#             */
/*   Updated: 2022/03/28 18:51:17 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_handler(t_ft_controller *ft_controller, t_strdata *strdata)
{
	ft_controller->stage = ft_read_conversion(strdata);
	if (ft_controller->stage < 0)
		exit(1);
	if (ft_controller->stage == FT_CONV_CHAR)
		ft_pf_handle_char(ft_controller, strdata);
	if (ft_controller->stage == FT_CONV_STR)
		ft_pf_handle_str(ft_controller, strdata);
	if (ft_controller->stage == FT_CONV_PTR)
		ft_pf_handle_ptr(ft_controller, strdata);
	if (ft_controller->stage == FT_CONV_OUXX)
		ft_pf_ouxX_handler(ft_controller, strdata);
	if (ft_controller->stage == FT_CONV_DI)
		ft_pf_handle_di(ft_controller, strdata);
	else
		return ;
}
