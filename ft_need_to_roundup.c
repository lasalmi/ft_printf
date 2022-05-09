/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_need_to_roundup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:47:00 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/09 15:19:10 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Bankers rounding with previous digit, otherwise to closest */
int	ft_need_to_round_up(double d, int precision)
{
	long long previous;
	long double remainder;

	remainder = (long double)d;
	if (!precision)
		previous = (long long)d;
	remainder -= (long long)d;
	while (precision--)
	{
		remainder *= 10.0L;
		if (precision == 0)
			previous = (long long)d;
		remainder -= (long long)d;
	}
	if (remainder > 0.5L || (previous % 2 != 0 && remainder == 0.5))
		return (1);
	return (0);
}

#include <stdio.h>

int main(void)
{
	double dee = 0.05;
	double bee = dee * 10.0L;
//	dee *= 10.0f;
	printf("%i", ft_need_to_round_up(dee, 1));
//	printf("\n%.20f", dee);
	return (0);
}