/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_skip_leading_zeroes.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:33:30 by lasalmi           #+#    #+#             */
/*   Updated: 2022/04/27 16:16:53 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_skip_leading_zeroes(char **str)
{
	if (**str != '0')
		return ;
	while (**str == '0')
		*str += 1;
}
