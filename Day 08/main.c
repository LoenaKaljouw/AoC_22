#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main()
{
    FILE *fp;
    char string[MAX_SIZE];
    int treeMap[MAX_SIZE][MAX_SIZE];
    int yValue = 0;
    
    fp = fopen("Day8.txt", "r");

    while (fgets(string, MAX_SIZE, fp))
    {
        for(int xValue = 0; string[xValue] != '\n';xValue++)
        {
            treeMap[yValue][xValue] = string[xValue] - 48;
        }
        yValue++;
    }

    for(int i = 0; i < MAX_SIZE;i++)
    {
        
    }
    printf("Final value is: %d", yValue);
}
