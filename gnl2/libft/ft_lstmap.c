/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/08 17:29:35 by kde-wint      #+#    #+#                 */
/*   Updated: 2019/04/11 12:33:21 by kde-wint      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;

	tmp = (*f)(lst);
	if (lst->next)
		tmp->next = ft_lstmap(lst->next, f);
	return (tmp);
}
