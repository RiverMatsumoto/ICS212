#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char str0[] = "a";
    char str1[] = "ad";
    char str2[] = "add";
    char ui_input[] = "a\n";
    char is_val_input;
    char input[200];
    int i;
    
    
    if (strlen(ui_input) <= 4 &&
        (strncmp(str2, ui_input, strlen(str2)) == 0 ||
        strncmp(str1, ui_input, strlen(str1)) == 0 ||
        strncmp(str0, ui_input, strlen(str0)) == 0))
    {
        printf("Add command enacted\n");
    }
    else
    {
        printf("Not valid add command\n");
    }

    is_val_input = 0;
    while (is_val_input != 1)
    {
        i = 0;
        while (i < 195 && (input[i] = getchar()) != '\\')
        {
            i++;
        }
        input[i] = '\0';
        is_val_input = 1;
    }

    printf("Input: %s\n", input);

    return 0;
}
