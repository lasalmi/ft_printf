/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_pad_with.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:48:44 by lasalmi           #+#    #+#             */
/*   Updated: 2022/04/27 15:29:10 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* Needs to be checked for handling signs for 0 padding */
t_status	ft_pf_pad_with(t_strdata *strdata, char c)
{
	int	padsize;

	padsize = strdata->width - strdata->strlen;
	strdata->padlen = padsize;
	strdata->padding = (char *)malloc(padsize + 1);
	if (!strdata->padding)
		return (MALLOCFAIL);
	while (--padsize >= 0)
		strdata->padding[padsize] = c;
	return (OKAY);
}
