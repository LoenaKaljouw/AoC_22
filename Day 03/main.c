#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 60

static int check(char string[], int size);
static int compare(char string[], char temp_data2[], int size);

int main(int argc, char const *argv[])
{
   FILE *fp;
   int count = 0;
   int first_value = 0;
   int second_value = 0;
   char temp_data1[MAX_SIZE];
   char temp_data2[MAX_SIZE];
   char string[MAX_SIZE];

   fp = fopen("Day3.txt", "r");

   while (fgets(string, MAX_SIZE, fp))
   {
      count++;
      int size = strlen(string);
      if (string[size - 1] == '\n')
      {
         size--;
      }

      if ((count % 3) == 1)
      {
         for (int i = 0; i < size; i++)
         {
            temp_data1[i] = string[i];
         }
      }
      else if ((count % 3) == 2)
      {
         int offset = 0;
         for (int i = 0; i < size; i++)
         {
            for (int j = 0; j < strlen(temp_data1); j++)
            {
               if (string[i] == temp_data1[j])
               {
                  temp_data2[offset] = temp_data1[j];
                  offset++;
                  break;
               }
            }
         }
      }
      else
      {
         second_value += compare(string, temp_data2, size);
      }
      first_value += check(string, size);
   }
   printf("The total priority is: %d \n", first_value);
   printf("The badge priority is: %d \n", second_value);
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

int compare(char string[], char temp_data2[], int size)
{
   for (int i = 0; i < size; i++)
   {
      for (int j = 0; j < strlen(temp_data2); j++)
      {
         if (string[i] == temp_data2[j])

         {
            printf("Badge number: %c\n", temp_data2[j]);
            return (temp_data2[j] - 38) % 58;
         }
      }
   }
}