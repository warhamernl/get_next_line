/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtoupper.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/13 14:36:17 by kde-wint      #+#    #+#                 */
/*   Updated: 2019/04/13 15:16:20 by kde-wint      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrev(const char *s)
{
	char	*ret;
	int		i;

	i = ft_strlen(s) - 1;
	ret = ft_strnew(i + 1);
	if (!ret)
		return (NULL);
	while (i >= 0 && *s)
	{
		ret[i] = *s;
		s++;
		i--;
	}
	return (ret);
}
