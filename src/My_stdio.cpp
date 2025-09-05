#include "My_stdio.h"
#include <assert.h>
#include <stdlib.h>

int My_puts(char const *str)
{
    while (*str != '\0')
    {
        if (fputc(*str++, stdout) == EOF)
        {
            return EOF;
        }
    }

    fputc('\n', stdout);
    return 0;
}

char *My_fgets(char *__restrict str, int count, FILE *__restrict stream)
{
    char *const ret_val = str;
    if (count < 1)
    {
        abort();
    }

    --count;
    int cur_c = fgetc(stream);
    if (cur_c == EOF)
    {
        return nullptr;
    }

    for (; count-- and cur_c != EOF;)
    {
        *str++ = (char) cur_c;
        if (cur_c == '\n')
        {
            break;
        }
        cur_c = fgetc(stream);
    }

    *str = '\0';
    return ret_val;
}
