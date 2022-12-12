#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
int inp, temp;

inp = 2347653;

printf("%d, %d", ((temp = inp / 10000), (inp %= 10000), (temp)), (temp = inp / 1000, inp %= 1000, temp));
printf("%d", inp);
}