/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_round_f_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 10:05:16 by lasalmi           #+#    #+#             */
/*   Updated: 2022/04/15 13:23:46 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static void ft_norounding(char *str, size_t i)
{
	str[i--] = '\0';
	if (str[i] == '.')
		str[i] = '\0';
}
static size_t ft_roundup(char *str, size_t len, t_strdata *strdata)
{
	size_t i;

	i = len - 1;
	if (str[i] == '.')
		i--;
	if (str[i] <= '8')
	{
		str[i] = str[i] + 1;
		str[i + 1] = '\0';
	}
	while (str[i] == '9' && i > 0)
	{
		str[i] = '0';
		i--;
		if (str[i] == '.')
			i--;
		if (str[i] <= '8' && str[i] >= '0')
			str[i] = str[i] + 1;
	}
	str[len] = '\0';
	return (i);
}

static int	ft_digit_is_odd(char c)
{
	return (c == '1' || c == '3' || c == '5' || c == '7' || c == '9');
}

static int	ft_preceding_is_even(char *str)
{
	if (*--str == '.')
		str--;
	return (!ft_digit_is_odd(*str));
}

static	void ft_integral_extends(char **str, size_t original_size)
{
	char	*to_free;
	size_t	i;

	i = 2;
	to_free = *str;
	*str = (char *)malloc(original_size + 1);
	str[0][0] = '1';
	str[0][1] = '0';
	while (to_free[i - 1])
	{
		str[0][i] = to_free[i - 1];
		i++;
	}
	free(to_free);
}

void	ft_pf_round_f_str(char **str, t_strdata *strdata, size_t i)
{
	size_t	rounding_i;
	if (str[0][i] <= '4' || (str[0][i] == '5' && ft_preceding_is_even(&str[0][i])))
	{
		ft_norounding(*str, i);
		return ;
	}
	rounding_i = ft_roundup(*str, i, strdata);
	if (rounding_i == 0 && str[0][rounding_i] == '9')
		ft_integral_extends(str, i);
}

int main(void)
{
	t_strdata strdata;

	strdata.explicit_zeroprec = 1;
	int i = 0;
	char *test = (char *)malloc(100);
	char	to_copy[] = "9.98765";
	while (to_copy[i])
	{
		test[i] = to_copy[i];
		i++;
	}
	test[i] = '\0';
	ft_pf_round_f_str(&test, &strdata, 6);
	printf("%s",test);
}