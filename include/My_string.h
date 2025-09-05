#ifndef MY_STRING_H
#define MY_STRING_H

#include <stdio.h>

char *My_strchr(char const *str, int ch);

size_t My_strlen(char const *str);

char *My_strcpy(char *__restrict dest, char const *__restrict src);

char *My_strncpy(char *__restrict dest, char const *__restrict src, size_t count);

char *My_strcat(char *__restrict dest, char const *__restrict src);

char *My_strncat(char *__restrict dest, char const *__restrict src, size_t count);

char *My_strdup(char const *src);

#endif
