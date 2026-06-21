#include <stdio.h>
#include <stdlib.h>

int get_tokens(char *string, char **tokens, int token_limit)
{
    int i = 0;
    int token = 0;

    while (string[i] == ' ')
        i++;

    if ((string[i] == '\0') || (string[i] == '\n')) {
        tokens[token] = NULL;
        return -1;
    }

    while (token < token_limit)
    {
        while (string[i] == ' ')
            i++;

        if (string[i] == '\0')
            break;
        else
            tokens[token] = &string[i];

        while ((string[i] != ' ') && (string[i] != '\0') && (string[i] != '\n')) {
            i++;
        }

        token++;

        if (string[i] != '\0')
            string[i++] = '\0';
        else
            break;
    }
    tokens[token] = NULL;

    return token;
}

int main(int argc, char *argv[])
{
    char *user_line = NULL;
    size_t line_size = 0;
    ssize_t errorcode = 0;

    char *tokens[1024];

    for (;;)
    {
        printf("zepto> ");
        errorcode = getline(&user_line, &line_size, stdin);
        if (errorcode != -1) {
            printf("You entered: %s", user_line);
            int token_count = get_tokens(user_line, tokens, (sizeof(tokens)/sizeof(tokens[0])));

            if (token_count > 0) {
                int i = 0;
                while (tokens[i] != NULL) {
                    printf("tokens[%d] = %s\n", i, tokens[i]);
                    i++;
                }
            }
        }
        else {
            printf("\n");
            break;
        }
    }

    free(user_line);
    return 0;
}
