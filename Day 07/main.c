#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

typedef struct Folder Folder;
typedef struct File File;
struct Folder
{
    Folder *parent;
    File *files[];
};

struct File
{
    int key;
};

File *new_file(int key)
{
    File *temp = malloc(sizeof(File));
    temp->key = key;
    return temp;
};

Folder *new_folder(Folder *parent)
{
    Folder *temp = malloc(sizeof(Folder));
    temp->parent = parent;
    return temp;
};

int main()
{
    FILE *fp;
    char string[MAX_SIZE];
    int value = 0;

    Folder *current_parent = new_folder(NULL);
    char *token;

    fp = fopen("Day7.txt", "r");

    while (fgets(string, MAX_SIZE, fp))
    {
        if (string[0] == '$')
        {
            token = strtok(string, "\n");
            token = strtok(string, " ");
            token = strtok(NULL, " ");
            if (token[0] == 'c')
            {
                token = strtok(NULL, " ");
                if (token[0] != '.')
                {
                    Folder *root = new_folder(current_parent);
                    current_parent = root;
                    printf("%s\n", token);
                }
                else
                {
                    printf("%s\n", token);
                    current_parent = current_parent->parent;
                }
            }
            else if (token[0] == 'l')
            {
                printf("%s\n", token);
            }
        }
        else if (token[0] > 47 && token[0] < 58)
        {
            token = strtok(string, " ");
            int size = 0;
            for (int i = 0; i < strlen(string); i++)
            {
                size = size * 10 + (string[i] - 48);
            }
            File *file = new_file(size);
            if (current_parent->files[0] == NULL)
            {
                current_parent->files[0] = file;
            }
            else
            {
                current_parent->files[0] = file;
            }
            printf("%d\n", size);
        }
    }
    printf("Final value is: %d", value);
}
