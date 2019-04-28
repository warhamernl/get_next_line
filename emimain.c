#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include "get_next_line.h"
#include "libft.h"

int    main(int argc, char **argv)
{
    int fds[8192];
    
    if (argc >= 2)
    {
        if (argv[1][0] == '@')
            goto errors;
        if (argv[1][0] == 'i')
            goto stdi;
        for (int i = 1; i < argc; i++)
        {
            fds[i - 1] = open(argv[i], O_RDONLY);
            if (fds[i - 1] == -1)
                break;
        } 
        char *str = NULL;
        int ret = 1;
        printf(" --- READING %s --- \n", argv[1]);
        while (1)
        {
            for (int i = 0; i < argc - 1; i++)
            {
                ret = get_next_line(fds[i], &str);
                printf("%i => %d: %s\n", i, ret, str);
                ft_strdel(&str);
                if (ret <= 0)
                    goto end;
            }
        }
        goto end;
stdi:
        {
            printf("Reading from stdin\n");
            int fd = 0;
            double avg = 0;
            int count = 0;
            char *s = NULL;
            int ret = 1;
            while ((ret = get_next_line(fd, &s)) > 0)
            {
                double number = atof(s);
                avg = ((avg * count) + number) / (count + 1);
                count++;
                printf("New average: %01lf\n", avg);
                free(s);
            }
        }
        goto end;
errors:
        {
            printf("Running special error checking\n");
            int    fd_dead = open("lol_i_don't_exist", O_RDONLY);
            int fd_real = open("author", O_RDONLY);
            printf("%d\n", fd_real);
            char *s = NULL;
            assert(-1 == get_next_line(-1, &s));
            assert(-1 == get_next_line(fd_dead, &s));
            assert(-1 == get_next_line(48393, &s));
            assert(-1 == get_next_line(493, &s));
            assert(-1 != get_next_line(fd_real, &s));
            assert(-1 == get_next_line(open("33232@@@", O_RDONLY), &s));
            printf("All tests passed, it seems\n");
        }
        goto skip;
end:
        printf(" --- end --- \n");
    }
skip:

    return (0);
}
