#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 4098
#define PACKET_SIZE 14
int main()
{
    FILE *fp;
    char string[MAX_SIZE];
    int value = 0;

    fp = fopen("Day6.txt", "r");

    while (fgets(string, MAX_SIZE, fp))
    {
        for (int i = 0; i < strlen(string); i++)
        {
            for (int j = 0; j < PACKET_SIZE; j++)
            {
                for (int k = 0; k < PACKET_SIZE; k++)
                {
                    if (string[i + j] == string[i + k])
                    {
                        if (j == k)
                        {
                        }
                        else
                        {
                            goto clone;
                        }
                    }
                }
            }
            break;
        clone:
            value++;
        }
    }
    printf("Final value is: %d", value + PACKET_SIZE);
}
