

#include <stdio.h>
#include <string.h>
#include "libRabinKarp/RabinKarp.h"
/*
int main()
{
    char str[] = "GEEKS FOR GEEKS";
    char underStr[] = "GEEK";
    // Простое число
    int q = 101;

    search(underStr, str, q);
    return 0;
}
*/
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
        search(template, path);
    }
    else
    {
        //! 0
        const char *template = argv[2]; // Шаблон
        const char *path = argv[3];     // Путь
        searchRecursive(template, path);
    }
    return 0;
}