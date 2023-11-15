#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 25
#define MAX_FOLDER_SIZE 100000
#define NEEDED_SPACE 30000000
#define MAX_SPACE 70000000

typedef struct Folder
{
    char name[MAX_SIZE];
    int size;
    int subfolderCount;
    struct Folder* subfolders[MAX_SIZE];
    struct Folder* parent;
} Folder;


int sizeCheck(Folder* folder)
{ 
    int size = 0;
    if(folder->subfolderCount == 0)
    {
        if(folder->size < MAX_FOLDER_SIZE)
        {
            return folder->size;
        }
        return 0;
    }
    for(int i = 0; i < folder->subfolderCount; i++)
    {
        size += sizeCheck(folder->subfolders[i]);
    }
    if(folder->size < MAX_FOLDER_SIZE)
    {
        return folder->size + size;
    }
    return size;
}

int spaceCheck(Folder* folder, int space)
{
    int size = 0;
    if(folder->subfolderCount == 0)
    {
        if(folder->size >= space)
        {
            return folder->size;
        }
        return 0;
    }
    for(int i = 0; i < folder->subfolderCount; i++)
    {
        int newSize = spaceCheck(folder->subfolders[i], space);
        if(size == 0)
        {
            size = newSize;
        }
        else if(newSize != 0 && newSize < size)
        {
            size = newSize;
        }
    }
    if(size != 0)
    {
        return size;
    }
    if(folder->size >= space)
    {
        return folder->size;
    }
    return 0;

}

int checkSmallest(Folder* folder)
{
    int current_space = MAX_SPACE - folder->size;
    int needed_space = NEEDED_SPACE - current_space;
    return spaceCheck(folder, needed_space);
}

int main()
{
    FILE *fp;
    char string[MAX_SIZE];
    int value = 0;

    fp = fopen("Day7.txt", "r");

    Folder system;
    system.name[0] = '/';
    system.size = 0;
    system.parent = NULL;
    system.subfolderCount = 0;

    Folder* currentFolder;
    currentFolder = &system;

    while (fgets(string, MAX_SIZE, fp))
    {
        if(string[0] == '$')
        {
            if(string[2] == 'c' && string[5] != '/')
            {   
                if(string[5] == '.')
                {
                    currentFolder = currentFolder->parent;
                }
                int nameSize = 0;
                for(nameSize = 5; nameSize < sizeof(string); nameSize++)
                {
                    if(string[nameSize]== '\n')
                    {
                        nameSize -= 5;
                        break;
                    }
                }
                for(int i = 0; i < currentFolder->subfolderCount; i++)
                {
                   int nameCheck = 0;
                   for(nameCheck = 0; nameCheck < nameSize; nameCheck++)
                   {
                        if(currentFolder->subfolders[i]->name[nameCheck] != string[nameCheck + 5])
                        {
                            break;
                        }
                   }
                   if(nameCheck == nameSize)
                   {
                        currentFolder = currentFolder->subfolders[i];
                   }
                }
            }   
        }
        else if (string[0] == 'd')
        {
            Folder* folder = (Folder*)malloc(sizeof(Folder));    
            
            if (folder == NULL)
            {
                fprintf(stderr, "Memory allocation failed\n");
                return 1;
            }  

            for(int i = 4; string[i] != '\n'; i++)
            {
                folder->name[i-4] = string[i];
            }

            folder->size = 0;
            folder->subfolderCount = 0;
            folder->parent = currentFolder;

            currentFolder->subfolders[currentFolder->subfolderCount] = folder;
            currentFolder->subfolderCount++;
        }
        else
        {  
            Folder* saveFolder = currentFolder;
            int size = 0;
            for(int i = 0; string[i] != ' '; i++)
            {
                size *= 10;
                size += string[i] - 48;
            }
            currentFolder->size += size;
            while(currentFolder->parent != NULL)
            {
                currentFolder = currentFolder->parent;
                currentFolder->size += size;
            }
            currentFolder = saveFolder;
        }
    }

    int finalValue = sizeCheck(&system);
    int finalSecondValue = checkSmallest(&system);

    printf("Final value is: %d, to free up that space you can remove a space of: %d", finalValue, finalSecondValue);
}
