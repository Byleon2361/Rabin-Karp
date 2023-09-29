#pragma once
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>
#include <sys/types.h>
#define b 256
bool rabinKarp(const char underStr[], const char str[], int q);
int searchRecursive(const char *template, const char *path);
int search(const char *template, const char *path);