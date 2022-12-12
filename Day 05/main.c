#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 56
#define MAX_BOX 6
#define BOXES 3
#define MOVE_POS 5
int main()
{
    FILE *fp;
    char string[MAX_SIZE];
    char boxes[BOXES][MAX_BOX];
    char boxes2[BOXES][MAX_BOX];

    int value = 0;
    int box_data = 0;
    int count = 0;

    fp = fopen("Day5.txt", "r");

    while (fgets(string, MAX_SIZE, fp))
    {
        if (!box_data)
        {
            for (int i = 0; i < strlen(string); i += 4)
            {
                if (string[i] == '[')
                {
                    boxes[i / 4][count] = string[i + 1];
                }
                else
                {
                    boxes[i / 4][count] = 0;
                }
            }
            count++;
        }
        else
        {
            int move_pos = MOVE_POS;

            int move = 0;
            int from = 0;
            int to = 0;
            while (string[move_pos] != ' ')
            {
                move = move * 10 + (string[move_pos] - 48);
                move_pos++;
            }
            from = string[move_pos + 6] - 48 - 1;
            to = string[move_pos + 11] - 48 - 1;

            for (int i = 0; i < move; i++)
            {
                for (int j = 0; j < count - 2; j++)
                {
                    if (boxes[from][j] != 0 || j == count - 3)
                    {
                        for (int k = 0; k < count - 2; k++)
                        {
                            if (boxes[to][k] != 0 || k == count - 3)
                            {
                                if (k == 0)
                                {
                                    for (int l = count - 2; l > 0; l--)
                                    {
                                        for (int m = 0; m < BOXES; m++)
                                        {
                                            boxes[m][l] = boxes[m][l - 1];
                                        }
                                    }
                                    for (int m = 0; m < BOXES; m++)
                                    {
                                        boxes[m][0] = 0;
                                    }
                                    count++;
                                    k++;
                                    j++;
                                }
                                boxes[to][k - 1] = boxes[from][j];
                                boxes[from][j] = 0;
                                k--;
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }
        if (string[0] == '\n')
        {
            box_data = 1;
        }
    }

    fclose(fp);

    printf("\n");
    printf("Final rearrangement wth the CrateMover 9000 is: ");

    for (int i = 0; i < BOXES; i++)
    {
        for (int j = 0; j < MAX_BOX; j++)
        {
            if (boxes[i][j] != 0)
            {
                printf("%c", boxes[i][j]);
                break;
            }
        }
    }
    printf("\n");

    value = 0;
    box_data = 0;
    count = 0;

    fp = fopen("Day5.txt", "r");

    while (fgets(string, MAX_SIZE, fp))
    {
        if (!box_data)
        {
            for (int i = 0; i < strlen(string); i += 4)
            {
                if (string[i] == '[')
                {
                    boxes2[i / 4][count] = string[i + 1];
                }
                else
                {
                    boxes2[i / 4][count] = 0;
                }
            }
            count++;
        }
        else
        {
            int move_pos = MOVE_POS;

            int move = 0;
            int from = 0;
            int to = 0;
            while (string[move_pos] != ' ')
            {
                move = move * 10 + (string[move_pos] - 48);
                move_pos++;
            }
            from = string[move_pos + 6] - 48 - 1;
            to = string[move_pos + 11] - 48 - 1;

            // for (int i = 0; i < move; i++)
            // {
            for (int j = 0; j < count - 2; j++)
            {
                if (boxes2[from][j] != 0 || j == count - 3)
                {
                    for (int k = 0; k < count - 2; k++)
                    {
                        if (boxes2[to][k] != 0 || k == count - 3)
                        {
                            for (int i = move; i > 0; i--)
                            {
                                if (k == 0)
                                {
                                    for (int l = count - 2; l > 0; l--)
                                    {
                                        for (int m = 0; m < BOXES; m++)
                                        {
                                            boxes2[m][l] = boxes2[m][l - 1];
                                        }
                                    }
                                    for (int m = 0; m < BOXES; m++)
                                    {
                                        boxes2[m][0] = 0;
                                    }
                                    count++;
                                    k++;
                                    j++;
                                }
                                boxes2[to][k - 1] = boxes2[from][j + i - 1];
                                boxes2[from][j + i - 1] = 0;
                                k--;
                            }
                            break;
                        }
                    }
                    break;
                }
            }
            // }
        }
        if (string[0] == '\n')
        {
            box_data = 1;
        }
    }

    printf("\n");
    printf("Final rearrangement wth the CrateMover 9001 is: ");

    for (int i = 0; i < BOXES; i++)
    {
        for (int j = 0; j < MAX_BOX; j++)
        {
            if (boxes2[i][j] != 0)
            {
                printf("%c", boxes2[i][j]);
                break;
            }
        }
    }

    printf("\n");
}
