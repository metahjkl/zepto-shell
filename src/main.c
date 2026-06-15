#include <stdio.h>

int main(int argc, char *argv[])
{
    char *user_line;
    size_t line_size = 0;
    ssize_t errorcode = 0;

    for (;;)
    {
        printf("zepto> ");
        errorcode = getline(&user_line, &line_size, stdin);
        if (errorcode != -1) {
            printf("You entered: %s", user_line);
        }
        else {
            printf("\n");
            break;
        }

    }

    return 0;
}
