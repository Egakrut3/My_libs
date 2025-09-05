#ifndef MY_STDIO_H
#define MY_STDIO_H

#include <stdio.h>

int My_puts(char const *str);

char *My_fgets(char *__restrict str, int count, FILE *__restrict stream);

#endif
