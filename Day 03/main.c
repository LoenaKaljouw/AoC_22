#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 104

static int check(char string[], int size);
static char *compare(char *string_one[], char *string_two[]);

int main(int argc, char const *argv[])
{
   FILE *fp;
   int count = 0;
   int first_value = 0;
   int second_value = 0;
   char base_data[MAX_SIZE];
   char string[MAX_SIZE];

   fp = fopen("Day3.txt", "r");

   while (fgets(string, MAX_SIZE, fp))
   {
      int size = strlen(string);
      if (string[strlen(string) - 1] == '\n')
      {
         size--;
      }

      first_value += check(string, size);

      if (count % 3 == 0)
      {
         for (int i = 0; i < size; i++)
         {
            base_data[i] = string[i];
            count++;
         }
      }
      else
      {
         char temp[MAX_SIZE];
         for (int i = 0; i < strlen(string); i++)
         {
            for (int j = 0; j < strlen(base_data); i++)
            {
               if (string[i] == base_data[j])
               {
                  temp[strlen(temp)] = base_data[j];
                  break;
               }
            }
         }
         count++;
         printf("The count is: %d \n", count);
      }
   }

   printf("The total priority is: %d \n", first_value);
   fclose(fp);

   return 0;
}

int check(char string[], int size)
{
   for (int i = 0; i < size / 2; i++)
   {
      for (int j = size / 2; j < size; j++)
      {
         if (string[i] == string[j])
         {
            return (string[j] - 38) % 58;
         }
      }
   }
}