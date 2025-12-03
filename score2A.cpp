// ¹è¿­

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
 
#pragma warning(disable: 4996 4326 6031)

void main()
{
    int scores[SIZE];
 
    for (int i = 0; i < SIZE; i++)
        scores[i] = rand() % 100;
    for (int i = 0; i < SIZE; i++)
        printf("scores[%d] = %d\n", i, scores[i]);
}