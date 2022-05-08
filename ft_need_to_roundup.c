/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_need_to_roundup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:47:00 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/08 15:52:04 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_need_to_round_up(double d, int precision)
{
	d -= (long long)d;

	while (precision--)
	{
		d *= 10;
		d -= (long long)d;
	}
	if (d > 0.5L)
		return (1);
	return (0);
}

#include <stdio.h>

int main(void)
{
	double dee = 1.45671;

	printf("%d", ft_need_to_round_up(dee, 3));
	return (0);
}