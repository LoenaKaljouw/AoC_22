#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

int main()
{
    FILE *fp;
    int value = 0;
    char string[MAX_SIZE];

    fp = fopen("Day4.txt", "r");

    while (fgets(string, MAX_SIZE, fp))
    {
        char *token = strtok(string, "\n");
        printf(" %s\n", token);
    }

    printf("Final value is: %d", value / 2);
}
