#include "RabinKarp.h"
bool rabinKarp(char underStr[], char str[], int q)
{
    int underStrSize = strlen(underStr);
    int strSize = strlen(str);
    int i, j;
    int underStrHash = 0; // хэш подстроки
    int strHash = 0;      // хэш строки
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < underStrSize - 1; i++)
        h = (h * d) % q;

    // Вычисление хэша для строки и подстроки
    for (i = 0; i < underStrSize; i++)
    {
        underStrHash = (d * underStrHash + underStr[i]) % q;
        strHash = (d * strHash + str[i]) % q;
    }

    for (i = 0; i <= strSize - underStrSize; i++)
    {

        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters one by one
        if (underStrHash == strHash)
        {
            /* Check for characters one by one */
            for (j = 0; j < underStrSize; j++)
            {
                if (str[i + j] != underStr[j])
                    break;
            }

            // if p == t and pat[0...M-1] = txt[i, i+1,
            // ...i+M-1]
            if (j == underStrSize)
                return true;
        }

        // Вычисляет хэш для следующей части строки
        if (i < strSize - underStrSize)
        {
            strHash = (d * (strHash - str[i] * h) + str[i + underStrSize]) % q;

            // We might get negative value of t, converting
            // it to positive
            if (strHash < 0)
                strHash = (strHash + q);
        }
    }
    return false;
}
void search(const char *template, const char *path)
{
    int q = 101; // Простое число
    DIR *dir;
    struct dirent *ent;
    dir = opendir(path);
    while ((ent = readdir(dir)) != false)
    {
        if (rabinKarp(template, ent->d_name, q))
        {
            path = strcat(path, "/");
            printf("%s\n", strcat(path, ent->d_name));
        }
    }
    closedir(dir);
}
void searchRecursive(const char *template, const char *path)
{
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
        }
        if ((ent->d_type == DT_DIR) && (strcmp(ent->d_name, "..")) && (strcmp(ent->d_name, ".")))
        {
            searchRecursive(template, temp);
        }
    }
    closedir(dir);
}
// set args -r ".c" ~/study