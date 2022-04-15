/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_conv_f2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:59:26 by lasalmi           #+#    #+#             */
/*   Updated: 2022/04/15 13:31:30 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void ft_get_decimal(long double nb, char *temp, t_strdata *strdata)
{
	int		decimal;
	size_t	count;
	size_t	i;

	count = (strdata->precision + 1);
	i = 0;
	temp[i++] = '.';
	nb -= (int)nb; 
	while (count--)
	{
		nb *= 10;
		temp[i++] = (int)nb + '0';
		nb -= (int)nb;
	}
	temp[i] = '\0';
}

static	void ft_get_integral(long double nb, char *temp)
{
	unsigned long long	integral;
	char				result[20];
	size_t				i;

	i = 18;
	result[19] = '\0';
	integral = (unsigned long long)nb;
	while (integral > 0)
	{
		result[i--] = (integral % 10) + '0';
		integral /= 10;
	}
	while (result[++i])
		*temp++ = result[i];
}

void	ft_pf_conv_f2(t_vardata *vardata, t_strdata *strdata, \
long double nb, char *str)
{
	char	*temp;

	temp = (char *)malloc((size_t)(vardata->intlen + strdata->precision + 5));
	if (!temp)
		exit(1);
	if (nb < 0)
		nb *= -1;
	ft_get_integral(nb, temp);
	ft_get_decimal(nb ,	temp + vardata->intlen, strdata);
	printf("%s\n", temp);
}

int	main(void)
{
	t_vardata varrit;
	t_strdata data;

	data.precision = 30;
	long double nb = 135.1234;
	varrit.intlen = 3;
	ft_pf_conv_f2(&varrit, &data, nb, NULL);
}