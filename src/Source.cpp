#include "My_stdio.h"
#include "My_string.h"
#include "My_stdlib.h"
#include <stdlib.h>

int main()
{
    char const *const str = "Hello";
    My_puts(str);

    char const c = 'l';
    printf("%td\n", My_strchr(str, c) - str);

    printf("%zu\n", My_strlen(str));

    char *const str_cp1 = (char *) calloc(10, sizeof(char));
    printf("%s\n", My_strcpy(str_cp1, str));

    char *const str_cp2 = (char *) calloc(3, sizeof(char));
    My_strncpy(str_cp2, str, 2)[2] = '\0';
    printf("%s\n", str_cp2);

    printf("%s\n", My_strcat(str_cp1, str_cp2));

    printf("%s\n", My_strncat(str_cp1, str_cp2, 1));

    printf("%d\n", My_atoi("   \n-134"));

    FILE *const inp_f = fopen("Input", "r");
    printf("%s\n", My_fgets(str_cp1, 4, inp_f));

    char *const str_cp3 = My_strdup(str_cp1);
    printf("%s\n", str_cp3);

    My_getline(inp_f, str_cp1, '\n');
    printf("%s\n", str_cp1);

    free(str_cp1);
    free(str_cp2);
    free(str_cp3);

    fclose(inp_f);

    printf("\n\n\nCommit GitHub\n\n");
}
