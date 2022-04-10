/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ouxX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:55:27 by lasalmi           #+#    #+#             */
/*   Updated: 2022/04/10 16:06:02 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void ft_conv_ouxX(unsigned long long nb, int base, size_t intlen, char *str)
{
	static const char	table[] = "0123456789abcdef";

	str[intlen--] = '\0';
	if (nb == 0	)
		str[intlen] = '0';
	while (nb > 0)
	{
		str[intlen] = table[nb%base];
		nb /= base;
		intlen--;
	}
}
