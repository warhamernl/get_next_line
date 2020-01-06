/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 06:59:42 by mlokhors       #+#    #+#                */
/*   Updated: 2020/01/06 06:59:44 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

int		main(int argc, char **argv)
{
	char	*str;
	int		fd;
	int		returned;

	returned = 1;
	if (argc < 2)
	{
		printf("please enter the filename(s) as arguments\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_putstr(KRED "open() error\n" KRED);
	while (returned == 1)
	{
		returned = get_next_line(fd, &str);
		printf("%s\n", str);
	}
	if (returned == -1)
		printf(KRED "error: get_next_line returned -1\n" KNRM);
	else if (returned == 0)
		printf(KGRN "get_next_line succesfully reached end of file\n" KNRM);
	close(fd);
	argc = 0;
	return (0);
}
