#include "My_stdio.h"
#include <stdlib.h>

int My_puts(char const *str)
{
    assert(str);

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

char *My_fgets(char *__restrict str, int count, FILE *__restrict const stream)
{
    assert(str and stream);

    char *const ret_val = str;
    if (count < 2)
    {
        abort();
    }

    count -= 2;
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
    *str++ = (char) cur_c;

    *str = '\0';
    return ret_val;
}
