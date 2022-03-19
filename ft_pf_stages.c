/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_stages.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:13:18 by lasalmi           #+#    #+#             */
/*   Updated: 2022/03/20 00:13:23 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_pf_set_stage_to(t_ft_controller *ft_controller, t_stage to)
{
	ft_controller->stage = to;
}
void ft_pf_stage_to_end(t_ft_controller *ft_controller)
{
	ft_controller->stage = FT_END;
}
void ft_pf_stage_to_read_spec(t_ft_controller *ft_controller)
{
	ft_controller->stage = FT_READ_SPEC;
}