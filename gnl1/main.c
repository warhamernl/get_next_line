#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"

int     main(int argc, char **argv)
{
    int i;
    int fds[10240];
    char *str;
    int ret;

    str = NULL;
    ret = 1;
    i = 1;
    if (argc >= 2)
    {
        while(i < argc)
        {
            fds[i - 1] = open(argv[i], O_RDONLY);
            if (fds[i - 1] == -1)
                break;
            if (fds[i - 1] >= 10240)
            {
                printf("limit reached");
                break;
            }    
            i++;
        }
        while(1)
        {
            i = 0;
            while(i < argc - 1)
            {
                ret = get_next_line(fds[i], &str);
                printf("%i => %d: %s\n", i, ret, str);
                ft_strdel(&str);
                if (ret <= 0)
                    return(0);
                i++;
            }
        }
    }
}

