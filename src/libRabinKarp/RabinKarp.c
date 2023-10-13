#include "RabinKarp.h"
bool rabinKarp(const char underStr[], const char str[], int q)
{
    int underStrSize = strlen(underStr);
    int strSize = strlen(str);
    int underStrHash = 0; // хэш подстроки
    int strHash = 0;      // хэш строки
    int h = 1;
    int i, j;
    // Значение h = "pow(d, M-1)%q"
    for (int i = 0; i < underStrSize - 1; i++)
        h = (h * b) % q;

    // Вычисление хэша для строки и подстроки
    for (i = 0; i < underStrSize; i++)
    {
        underStrHash = (b * underStrHash + underStr[i]) % q;
        strHash = (b * strHash + str[i]) % q;
    }

    for (i = 0; i <= strSize - underStrSize; i++)
    {

        // Проверьте хеш-значения текущего окна текста и шаблона.
        if (underStrHash == strHash)
        {
            // проверяем символы один за другим, так как могут быть коллизии
            for (j = 0; j < underStrSize; j++)
            {
                if (str[i + j] != underStr[j])
                    break;
            }
            if (j == underStrSize)
            {
                return true;
            }
        }

        // Вычисляет хэш для следующей части строки
        if (i < strSize - underStrSize)
        {
            strHash = (b * (strHash - str[i] * h) + str[i + underStrSize]) % q;

            // Мы могли бы получить отрицательное значение strHash,
            // преобразуем его к положительному
            if (strHash < 0)
                strHash = (strHash + q);
        }
    }
    return false;
}

int search(const char *template, const char *path)
{
    char temp[1000];
    int countFind = 0;
    int q = 101; // Простое число
    DIR *dir;
    struct dirent *ent;
    dir = opendir(path);
    while ((ent = readdir(dir)) != false)
    {
        if (rabinKarp(template, ent->d_name, q))
        {
            countFind++;
            memset(temp, '\0', 1000);
            strcat(temp, path);
            strcat(temp, "/");
            printf("%s\n", strcat(temp, ent->d_name));
        }
    }
    closedir(dir);
    return countFind;
}
int searchRecursive(const char *template, const char *path)
{
    static int countFind = 0;
    char temp[1000];
    int q = 101; // Простое число
    DIR *dir;
    struct dirent *ent;
    dir = opendir(path);
    while ((ent = readdir(dir)) != false)
    {
        strcpy(temp, path);
        strcat(temp, "/");
        strcat(temp, ent->d_name);
        if (rabinKarp(template, ent->d_name, q))
        {
            printf("%s\n", temp);
            countFind++;
        }
        if ((ent->d_type == DT_DIR) && (strcmp(ent->d_name, "..")) && (strcmp(ent->d_name, ".")))
        {
            searchRecursive(template, temp);
        }
    }
    closedir(dir);
    return countFind;
}