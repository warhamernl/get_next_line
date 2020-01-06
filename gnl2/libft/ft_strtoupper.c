/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtoupper.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/13 15:26:43 by kde-wint      #+#    #+#                 */
/*   Updated: 2019/04/13 17:29:32 by kde-wint      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_toupperchar(char c)
{
	return ((char)ft_toupper((int)c));
}

char		*ft_strtoupper(const char *s)
{
	return (ft_strmap(s, ft_toupperchar));
}
