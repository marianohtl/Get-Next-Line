#include <stdlib.h>
#include <stdio.h>

// void    *broken(void)
// {
//     static char    buffer[100000000000000000];
//     return (NULL);
// }

void    *working(void)
{
    static char    *buffer;
    buffer = malloc(sizeof(*buffer) * 1000000000000000000);
    return (buffer);
}

int    main(void)
{
    // printf("Broken return: %p\n", broken());
    printf("Working return: %p\n", working());
}