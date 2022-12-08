#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 7

int highest_top[MAX_SIZE - 2];
int highest_bottom[MAX_SIZE - 2];

int main()
{
    FILE *fp;
    int map[MAX_SIZE - 2][MAX_SIZE - 2];
    char string[MAX_SIZE];
    int highest_left = 0;
    int highest_right = 0;
    int value = 0;
    int pos = 0;

    fp = fopen("Day8.txt", "r");

    while (fgets(string, MAX_SIZE, fp))
    {
        for (int i = 0; i < MAX_SIZE - 1; i++)
        {
            map[pos][i] = string[i] - 48;
        }
        pos++;
    }

    value += (MAX_SIZE - 2) * 4 - 4;

    for (int y = 1; y < MAX_SIZE - 3; y++)
    {
        highest_left = map[y][0];
        for (int x = 1; x < MAX_SIZE - 3; x++)
        {
            if (map[y][x] > highest_left)
            {
                highest_left = map[y][x];
            }
            if (map[y][x] > highest_top[x])
            {
                highest_top[x] = map[y][x];
            }
            else if (map[y][x] < highest_left)
            {
                value++;
            }
        }
    }

     for (int y = 1; y < MAX_SIZE - 3; y++)
    {
        highest_left = map[y][0];
        for (int x = 1; x < MAX_SIZE - 3; x++)
        {
            if (map[y][x] > highest_left)
            {
                highest_left = map[y][x];
            }
            if (map[y][x] > highest_top[x])
            {
                highest_top[x] = map[y][x];
            }
            else if (map[y][x] < highest_left)
            {
                value++;
            }
        }
    }

    printf("Final value is: %d", value);
}
