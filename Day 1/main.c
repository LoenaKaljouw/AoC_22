#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

int main()
{  
   FILE *fp;
   int current_elf = 0;
   int highest_elfs[3] = {0,0,0};
   int top_elfs = 0;
   char string[MAX_SIZE];

   fp = fopen("Day1.txt" , "r");
   
   while(fgets(string, MAX_SIZE, fp)) {
       if(string[0] == '\n')
       {
        for(int i = 0; i < 3; i++)
        {
          if(current_elf > highest_elfs[i])
          {
            highest_elfs[i] = current_elf;
            break;
          }
        }
        current_elf = 0;
       }
       current_elf += atoi(string);
   }
   
   for(int i = 0 ; i < 3; i++)
   {
      top_elfs += highest_elfs[i];
      itoa(highest_elfs[i], string, MAX_SIZE);
      printf("%s\n", string);
   }
   
   itoa(top_elfs, string, MAX_SIZE);
   printf("%s\n", string);
   fclose(fp);
  
   return 0;
}
