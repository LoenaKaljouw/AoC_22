#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

int main()
{
    FILE *fp;
    char string[MAX_SIZE];
    int value = 0;
    
    fp = fopen("DayX.txt", "r");

    while (fgets(string, MAX_SIZE, fp))
    {
    }
    printf("Final value is: %d", value);
}
