#pragma once
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>
#define d 256
bool rabinKarp(char underStr[], char str[], int q);
void searchRecursive(const char *template, const char *path);
void search(const char *template, const char *path);