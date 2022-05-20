/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_need_to_roundup.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:47:00 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/20 14:00:40 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Bankers rounding with previous digit, otherwise to closest */
int	ft_pf_need_upround(double d, int precision)
{
	long long	previous;
	long double	remainder;

	remainder = (long double)d;
	if (!precision)
		previous = (long long)d;
	remainder -= (long long)d;
	while (precision--)
	{
		remainder *= 10.0L;
		if (precision == 0)
			previous = (long long)remainder;
		remainder -= (long long)remainder;
	}
	if (remainder > 0.5L || (previous % 2 != 0 && remainder == 0.5))
		return (1);
	return (0);
}
