#include "My_stdlib.h"
#include <ctype.h>

int My_atoi(char const *str)
{
    while (isspace(*str))
    {
        ++str;
    }

    char cur_c = *str++;
    bool is_neg = false;
    int cur_abs = 0;
    if (cur_c == '+')
    {
        cur_c = *str++;
        if (!(cur_c >= '0' and cur_c <= '9'))
        {
            return 0;
        }
    }
    else if (cur_c == '-')
    {
        is_neg = true;
        cur_c = *str++;
        if (!(cur_c >= '0' and cur_c <= '9'))
        {
            return 0;
        }
    }
    else if (!(cur_c >= '0' and cur_c <= '9'))
    {
        return 0;
    }

    while (cur_c >= '0' and cur_c <= '9')
    {
        cur_abs = cur_abs * 10 + cur_c - '0';
        cur_c = *str++;
    }

    if (is_neg)
    {
        return -cur_abs;
    }
    else
    {
        return +cur_abs;
    }
}


