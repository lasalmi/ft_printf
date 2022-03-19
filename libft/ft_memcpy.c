/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:02:48 by lasalmi           #+#    #+#             */
/*   Updated: 2021/12/05 16:09:08 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*copysource;
	char	*copydest;
	int		i;

	copysource = (char *)src;
	copydest = (char *)dest;
	i = 0;
	if (!dest && !src)
		return (dest);
	while (n > 0)
	{
		copydest[i] = copysource[i];
		n--;
		i++;
	}
	return (dest);
}
