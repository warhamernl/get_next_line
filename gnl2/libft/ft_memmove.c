/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 19:23:00 by kde-wint      #+#    #+#                 */
/*   Updated: 2019/04/11 10:37:40 by kde-wint      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if ((size_t)dst - (size_t)src < len)
	{
		while (i < len)
		{
			((unsigned char *)dst)[len - i - 1] =
				((unsigned char *)src)[len - i - 1];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char*)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return ((void *)dst);
}
