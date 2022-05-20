/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_skip_leading_zeroes.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:33:30 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/20 20:42:23 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_skip_leading_zeroes(const char **str)
{
	if (**str != '0')
		return ;
	while (**str == '0')
		*str += 1;
}
