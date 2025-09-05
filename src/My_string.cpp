#include "My_string.h"
#include <stdlib.h>

char *My_strchr(const char *str, int const ch) //TODO - bad conversations
{
    for (; *str != '\0'; ++str)
    {
        if (*str == ch)
        {
            return (char *) str;
        }
    }

    if (*str == ch)
    {
        return (char *) str;
    }

    return nullptr;
}

size_t My_strlen(const char *str)
{
    size_t cur_len = 0;
    while (*str++ != '\0')
    {
        ++cur_len;
    }

    return cur_len;
}

char *My_strcpy(char *__restrict dest, const char *__restrict src)
{
    char *const ret_val = dest;
    while (*src != '\0')
    {
        *dest++ = *src++;
    }

    *dest = '\0';
    return ret_val;
}

char *My_strncpy(char *__restrict dest, const char *__restrict src, size_t count)
{
    char *const ret_val = dest;
    for (; count and *src != '\0'; --count) //TODO - weak spot
    {
        *dest++ = *src++;
    }

    while (count--)
    {
        *dest++ = '\0';
    }

    return ret_val;
}

char *My_strcat(char *__restrict dest, const char *__restrict src)
{
    char *const ret_val = dest;
    for (dest = My_strchr(dest, '\0'); *src != '\0';)
    {
        *dest++ = *src++;
    }

    *dest = '\0';
    return ret_val;
}

char *My_strncat(char *__restrict dest, const char *__restrict src, size_t count)
{
    char *const ret_val = dest;
    for (dest = My_strchr(dest, '\0'); count-- and *src != '\0';)
    {
        *dest++ = *src++;
    }

    *dest = '\0';
    return ret_val;
}

char *My_strdup(char const *src) //TODO - I can't set errno
{
    char *const dest = (char *) malloc(My_strlen(src) * sizeof(char));
    if (!dest)
    {
        return nullptr;
    }

    return My_strcpy(dest, src);
}
