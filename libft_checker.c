/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnegre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:58:27 by pnegre            #+#    #+#             */
/*   Updated: 2023/04/19 08:59:07 by pnegre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0') & (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;
	size_t				len_s;
	size_t				len_d;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	len_s = ft_strlen(src);
	len_d = ft_strlen(dst);
	if (len_d > dstsize)
		return (len_s + dstsize);
	while (i + len_d + 1 < dstsize && s[i])
	{
		d[i + len_d] = s[i];
		i++;
	}
	if (dstsize > 0 && len_d < dstsize)
		d[i + len_d] = '\0';
	return (len_s + len_d);
}
