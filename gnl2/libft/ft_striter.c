/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 08:52:51 by kde-wint      #+#    #+#                 */
/*   Updated: 2019/04/11 11:39:14 by kde-wint      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char *))
{
	while (*s)
	{
		f(s);
		s++;
	}
}