#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

typedef struct Folder Folder;
typedef struct File File;
struct Folder
{
    Folder* parent;
    File* files[];
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

    Folder current_parent = NULL;
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
                if(token[0] == '/')
                {
                    Folder *root = new_folder(current_parent); 
                }
                else
                {
                    Folder *root = new_folder(current_parent);
                }
                printf("%s\n", token);
            }
            else if (token[0] == 'l')
            {
                printf("%s\n", token);
            }
        }
    }
    printf("Final value is: %d", value);
}
