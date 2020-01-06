/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 17:29:08 by mlokhors       #+#    #+#                */
/*   Updated: 2019/05/09 12:55:00 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	eof(t_list **remain, char **line, int total_read)
{	
	char	*str;
	char	*linebreak;
	t_list	*garbage;

	if (total_read == 0 && *(char *)(*remain)->content == '\0')
	{
		*line = NULL;
		free((*remain)->content);
		free(*remain);
		return (0);
	}
	if ((*remain)->next && *(char *)(*remain)->next->content != '\0')
	{
		linebreak = ft_strchr((*remain)->content, '\n');
		str = (linebreak) ? ft_strdup(linebreak + 1) : ft_strdup((*remain)->content);
		while ((*remain)->next)
		{
			garbage = (t_list *)(*remain);
			*remain = (t_list *)(*remain)->next;
			free(garbage->content);
			free(garbage);
			str = ft_strjoin(str, (*remain)->content);
		}
		ft_strreplace((char **)&(*remain)->content, ft_strdup(str));
		free(str);
	}
	linebreak = ft_strchr((*remain)->content, '\n');
	if (linebreak)
	{
		*line = ft_strndup((*remain)->content, linebreak - (char *)(*remain)->content);
		ft_strreplace((char **)&((*remain)->content), ft_strdup(linebreak + 1));
		return (1);
	}
	else
	{
		*line = ft_strdup((*remain)->content);
		((char *)(*remain)->content)[0] = '\0';
		return (1);
	}
}

static char	*linker(t_list **remain, t_list **buff, char *linebreak, int total_read)
{
	int			strsize;
	char		*str;
	char		*strwalker;
	t_list		*garbage;

	strwalker = (ft_strchr((char *)(*remain)->content, '\n'));
	if (strwalker == NULL && *remain)
		strwalker = (*remain)->content;
	if (strwalker)
		strsize = ((ft_strlen((*remain)->content) - ((strwalker) - (char *)(*remain)->content)) + total_read - (BUFF_SIZE - (linebreak - (char *)(*buff)->content))); /// stond een -1
	else
		strsize = total_read - (BUFF_SIZE - (linebreak - (char *)(*buff)->content)); // zitten hier nog haken en/of ogen aan? testing required.
	str = (char *)malloc(sizeof(char) * (strsize + 1));
	if (!str)
		return (NULL);
	while (strwalker != linebreak)// linebreak zal ook moeten werken wanneer een line niet in een \n eindigt
	{
		if (strwalker == NULL || *strwalker == '\0')
		{
			garbage = (t_list *)(*remain);
			*remain = (t_list *)(*remain)->next;
			free(garbage->content);
			free(garbage);
			strwalker = (char *)(*remain)->content;
			continue;
		}
		*str = *strwalker;
		strwalker++;
		str++;
	}
	ft_strreplace((char **)&((*remain)->content), ft_strdup(linebreak + 1));
	*str = '\0';
	str -= (strsize);
	return (str);
}

int         get_next_line(const int fd, char **line)
{
	int				bytes_read;
	int				total_read;
	t_list			*buff;
	static t_list	*remain;
	char        	*linebreak;
	
	if (remain && ((char *)(remain)->content)[0] == '\n')
	{
		*line = ft_strnew(0);
		ft_strreplace((char **)&(remain->content), ft_strdup((char *)&(remain->content)[1]));
		return (1);
	}
	bytes_read = BUFF_SIZE;
	total_read = 0;
	linebreak = NULL;
	buff = ft_lstalloc(BUFF_SIZE + 1);
	if (!buff || !(buff->content))
		return (-1);
	ft_bzero(buff->content, BUFF_SIZE + 1);
	if (read(fd, buff->content, 0) < 0 || fd < 0 || BUFF_SIZE == 0)
	{
		free(buff->content);
		free(buff);
    	return (-1);
	}
	if (remain == NULL)
	{
		remain = ft_lstalloc(BUFF_SIZE + 1);
		if (!remain || !(remain->content))
			return (-1);
		ft_bzero(remain->content, BUFF_SIZE + 1);
	}
	remain->next = buff;
  	while (linebreak == NULL && bytes_read == BUFF_SIZE)
  	{
		bytes_read = read(fd, buff->content, BUFF_SIZE);
		total_read += bytes_read;
		linebreak = ft_strchr(buff->content, '\n');
		if (bytes_read == BUFF_SIZE && linebreak == NULL)
		{
			buff->next = ft_lstalloc(BUFF_SIZE + 1);
			if (!buff->next || !(buff->next->content))
				return (-1);
			buff = buff->next;
			((char *)(buff)->content)[BUFF_SIZE] = '\0';
		}
  	}
	if (bytes_read < BUFF_SIZE)
	{
		if (bytes_read == 0)
		{
			free(buff->content);
			free(buff);
		}
		else
			((char *)buff->content)[bytes_read] = '\0';
		return(eof(&remain, line, total_read));
	}
	else
	{
		*line = linker(&remain, &buff, linebreak, total_read);
		if (*line == NULL)
			return (-1);
		return (1);
	}
}