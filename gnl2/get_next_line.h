/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 17:31:55 by mlokhors       #+#    #+#                */
/*   Updated: 2019/05/18 17:18:08 by kde-wint      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 4000
# include <libft.h>

int	get_next_line(const int fd, char **line);

#endif
