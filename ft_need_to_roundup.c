/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_need_to_roundup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:47:00 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/08 16:58:49 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Bankers rounding with previous digit, otherwise to closest */
int	ft_need_to_round_up(double d, int precision)
{
	long long previous;

	if (!precision)
		previous = (long long)d;
	d -= (long long)d;
	while (precision--)
	{
		d *= (double)10.0;
		if (precision == 0)
			previous = (long long)d;
		d -= (long long)d;
	}
	if (d > 0.5L || (previous % 2 != 0 && d == 0.5))
		return (1);
	return (0);
}

#include <stdio.h>

int main(void)
{
	double dee = 1.5550;

	printf("%.3f %d", dee, ft_need_to_round_up(dee, 3));
	return (0);
}