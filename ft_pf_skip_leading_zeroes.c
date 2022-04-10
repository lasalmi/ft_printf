/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_skip_leading_zeroes.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:33:30 by lasalmi           #+#    #+#             */
/*   Updated: 2022/04/10 12:45:13 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_skip_leading_zeroes(char **str)
{
	if (!ft_isdigit(**str))
		return ;
	while (ft_isdigit(**str))
		*str += 1;
	*str -= 1;
}