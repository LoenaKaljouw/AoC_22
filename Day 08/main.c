#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 7

int highest_top[MAX_SIZE - 2];
int highest_bottom[MAX_SIZE - 2];
int map_found[MAX_SIZE - 2][MAX_SIZE - 2];

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

    for (int i = 0; i < MAX_SIZE - 2; i++)
    {
        highest_top[i] = map[0][i];
        highest_bottom[i] = map[MAX_SIZE - 3][i];
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
                if (map_found[y][x] != 1)
                {
                    map_found[y][x] = 1;
                    value++;
                }
            }
            if (map[y][x] > highest_top[x])
            {
                highest_top[x] = map[y][x];
                if (map_found[y][x] != 1)
                {
                    map_found[y][x] = 1;
                    value++;
                }
            }
        }
    }

    for (int y = MAX_SIZE - 4; y > 0; y--)
    {
        highest_right = map[MAX_SIZE - 3 - (MAX_SIZE - 3 - y)][MAX_SIZE - 3];
        for (int x = MAX_SIZE - 4; x > 0; x--)
        {
            if (map[y][x] > highest_right)
            {
                highest_right = map[y][x];
                if (map_found[y][x] != 1)
                {
                    map_found[y][x] = 1;
                    value++;
                }
            }
            if (map[y][x] > highest_bottom[x])
            {
                highest_bottom[x] = map[y][x];
                if (map_found[y][x] != 1)
                {
                    map_found[y][x] = 1;
                    value++;
                }
            }
        }
    }
    printf("Final value is: %d\n", value);

    value = 0;
    int tempup = 0;
    int templeft = 0;
    int tempdown = 0;
    int tempright = 0;

    for (int y = 0; y < MAX_SIZE - 2; y++)
    {
        for (int x = 0; x < MAX_SIZE - 2; x++)
        {
            for (int i = y - 1; i != MAX_SIZE; i--)
            {
                if (i < 0)
                {
                    tempup = y;
                    break;
                }
                else if ((map[y][x] <= map[i][x]))
                {
                    tempup = y - i;
                    break;
                }
            }
            for (int i = y + 1; i != MAX_SIZE; i++)
            {
                if (i >= (MAX_SIZE - 2))
                {
                    tempdown = i - y - 1;
                    break;
                }
                else if (map[y][x] <= map[i][x])
                {
                    tempdown = i - y;
                    break;
                }
            }
            for (int i = x - 1; i != MAX_SIZE; i--)
            {
                if (i < 0)
                {
                    templeft = x;
                    break;
                }
                else if (map[y][x] <= map[y][i] || i == 0)
                {
                    templeft = x - i;
                    break;
                }
            }
            for (int i = x + 1; i != MAX_SIZE; i++)
            {
                if (i >= (MAX_SIZE - 2))
                {
                    tempright = i - x - 1;
                    break;
                }
                else if (map[y][x] <= map[y][i])
                {
                    tempright = i - x;
                    break;
                }
            }
            if (!tempdown)
            {
                tempdown = 1;
            }
            if (!templeft)
            {
                templeft = 1;
            }
            if (!tempright)
            {
                tempright = 1;
            }
            if (!tempup)
            {
                tempup = 1;
            }
            if ((tempdown * templeft * tempright * tempup) > value)
            {
                value = (tempdown * templeft * tempright * tempup);
                printf("Final value is: %d", value);
            }
        }
    }
}
