#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

int main()
{
  FILE *fp;
  int current_elf = 0;
  int highest_elfs[3] = {0, 0, 0};
  int top_elfs = 0;
  char string[MAX_SIZE];

  fp = fopen("Day4.txt", "r");

  while (fgets(string, MAX_SIZE, fp))
  {
    for(int i = string[0]; i < string[2]; i++)
    {
        
    }
    printf("\n");
  }

}
