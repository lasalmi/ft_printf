/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_conv_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:39:53 by lasalmi           #+#    #+#             */
/*   Updated: 2022/03/28 18:40:22 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void ft_conv_di(long long nb, int base, size_t intlen, char *str)
{
	static const char	table[] = "0123456789abcdef";

	str[intlen--] = '\0';
	if (nb == 0)
		str[intlen] = '0';
	while (nb > 0)
	{
		str[intlen] = table[nb%base];
		nb /= base;
		intlen--;
	}
}
