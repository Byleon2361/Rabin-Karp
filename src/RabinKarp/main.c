

#include <stdio.h>
#include <string.h>
#include "libRabinKarp/RabinKarp.h"
int main(int argc, char *argv[])
{
    if (argc > 4)
    {
        puts("The number of arguments passed must be three");
        return 0;
    }
    if (strcmp(argv[1], "-r") != 0)
    {
        const char *template = argv[1]; // Шаблон
        const char *path = argv[2];     // Путь
        printf("%d\n", search(template, path));
    }
    else
    {
        //! 0
        const char *template = argv[2]; // Шаблон
        const char *path = argv[3];     // Путь
        printf("%d\n", searchRecursive(template, path));
    }
    return 0;
}