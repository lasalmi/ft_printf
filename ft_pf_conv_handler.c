/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_conv_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:26:56 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/18 15:16:15 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_handler(t_pf_controller *pf_controller, t_strdata *strdata)
{
	pf_controller->stage = ft_read_conversion(strdata);
	if (pf_controller->stage < 0)
		exit(1);
	if (pf_controller->stage == FT_CONV_CHAR)
		ft_pf_handle_char(pf_controller, strdata);
	if (pf_controller->stage == FT_CONV_STR)
		ft_pf_handle_str(pf_controller, strdata);
	if (pf_controller->stage == FT_CONV_PTR)
		ft_pf_handle_ptr(pf_controller, strdata);
	if (pf_controller->stage == FT_conv_oux)
		ft_pf_oux_handler(pf_controller, strdata);
	if (pf_controller->stage == FT_CONV_DI)
		ft_pf_handle_di(pf_controller, strdata);
	if (pf_controller->stage == FT_CONV_FLOAT)
		ft_pf_handle_f(pf_controller, strdata);
	else
		return ;
}
