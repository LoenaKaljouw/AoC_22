#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

int main()
{
    FILE *fp;
    char string[MAX_SIZE];
    int value = 0;

    char* token;

    fp = fopen("Day7.txt", "r");

    while (fgets(string, MAX_SIZE, fp))
    {
        if(string[0] == '$')
        {
            if(string[2] == 'c')
            {
                token = strtok(string, " ");
                token = strtok(NULL, '\n');
                token = strtok(NULL, "\n");
                printf("%s\n", token);
            }
            else
            {

            }
        }
    }
    printf("Final value is: %d", value);
}
