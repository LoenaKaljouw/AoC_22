#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

int main()
{
    FILE *fp;
    int value = 0;
    char *token;
    char string[MAX_SIZE];
    int lhs1 = 0;
    int rhs1 = 0;
    int lhs2 = 0;
    int rhs2 = 0;

    fp = fopen("Day4.txt", "r");

    while (fgets(string, MAX_SIZE, fp))
    {
        token = strtok(string, "-");
        for (int i = 0; i < strlen(token); i++)
        {
            lhs1 = lhs1 * 10 + (token[i] - 48);
        }

        token = strtok(NULL, ",");
        for (int i = 0; i < strlen(token); i++)
        {
            rhs1 = rhs1 * 10 + (token[i] - 48);
        }

        token = strtok(NULL, "-");
        for (int i = 0; i < strlen(token); i++)
        {
            lhs2 = lhs2 * 10 + (token[i] - 48);
        }

        token = strtok(NULL, "\n");
        for (int i = 0; i < strlen(token); i++)
        {
            rhs2 = rhs2 * 10 + (token[i] - 48);
        }

        if (lhs1 >= lhs2 && lhs1 <= rhs2 || lhs1 <= lhs2 && rhs1 >= rhs2 || lhs1 <= lhs2 && rhs1 >= lhs2 || rhs1 <= rhs2 && rhs1 >= lhs2)
        {
            value++;
        }

        lhs1 = 0;
        rhs1 = 0;
        lhs2 = 0;
        rhs2 = 0;
    }
    printf("Final value is: %d", value);
}
