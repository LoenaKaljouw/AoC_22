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
        int pos1;
        int pos2;
        int pos3;
        int pos4;       
        for(int i = 0; i < strlen(string); i++)
        {
            
        }
    }

    printf("Final value is: %d", value / 2);
}
