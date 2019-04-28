#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include "get_next_line.h"
#include "libft.h"

int     main(int argc, char **argv)
{
    int i;
    int fds[10240];

    i = 2;

    if (argc >= 2)
    {
        while (i < argc)
        {
            fd[i - 1] = open(argv[i])
            if (fd[i - 1] == -1)
                break;
            i++;
        }
        while (get_next_line == 1)
    }
}