#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 4

int main()
{
   FILE *fp;
   double score = 0;
   double score_2 = 0;
   char string[MAX_SIZE];

   fp = fopen("Day2.txt", "r");

   while (fgets(string, MAX_SIZE, fp))
   {
      if (string[0] != '\n')
      {
         int pvalue = (string[2] - string[0]) % 3;

         score += string[2] - 87;
         score += 4.5 * pow(pvalue, 2) - (10.5 * pvalue) + 6;

         pvalue = (string[0] + string[2]) % 3;

         score_2 += (string[2] - 88) * 3;
         score_2 += abs(-1.5 * pow(pvalue, 2) + (5.5 * pvalue) - 3);
      }
   }

   printf("\nThe score for the first part is: %.0f \n", score);
   printf("The score for the second part is: %.0f \n", score_2);
   fclose(fp);

   return 0;
}
