/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_mallocfail.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:30:22 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/25 14:32:17 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_mallocfail(t_pf_controller *pf_controller, t_strdata *strdata)
{
	free(strdata->variable_str);
	strdata->variable_str = NULL;
	free(strdata->padding);
	strdata->padding = NULL;
	exit(1);
}
