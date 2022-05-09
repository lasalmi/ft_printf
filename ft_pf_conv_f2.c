/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_conv_f2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:59:26 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/09 18:36:49 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	ft_get_decimal(long double nb, char *temp, \
size_t i, t_strdata *strdata)
{
	int		decimal;
	size_t	count;

	count = strdata->precision + 1;
	temp[i++] = '.';
	nb -= (long long)nb;
	while (count--)
	{
		nb *= 10;
		temp[i++] = (int)nb + '0';
		nb -= (long long)nb;
	}
	temp[i] = '\0';
	return (i - 1);
}

static	size_t	ft_get_integral(long double nb, char *temp)
{
	unsigned long long	integral;
	char				result[20];
	size_t				i;
	size_t				j;

	j = 0;
	i = 18;
	result[19] = '\0';
	integral = (unsigned long long)nb;
	if (!integral)
	{
		temp[j++] = '0';
		return (j);
	}
	while (integral > 0)
	{
		result[i--] = (integral % 10) + '0';
		integral /= 10;
	}
	while (result[++i])
		temp[j++] = result[i];
	return (j);
}

void	ft_pf_conv_f(t_vardata *vardata, t_strdata *strdata, \
long double nb, char *str)
{
	char	*temp;
	size_t	i;

	temp = (char *)malloc((size_t)(vardata->intlen + strdata->precision + 5));
	if (!temp)
		exit(1);
	if (nb < 0)
		nb *= -1;
	i = ft_get_integral(nb, temp);
	i = ft_get_decimal(nb, temp, i, strdata);
	ft_pf_round_f_str(&temp, strdata, i, nb);
	i = 0;
	while (temp[i])
		*str++ = temp[i++];
	free(temp);
}

/*int	main(void)
{
	t_vardata varrit;
	t_strdata data;

	data.precision = 2;
	long double nb = 3.9999;
	varrit.intlen = 1;
	char result[50];
	ft_pf_conv_f2(&varrit, &data, nb, result);
	printf("%s", result);
} */