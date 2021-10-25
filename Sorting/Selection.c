#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j]< array[min])
            {
                min = j;
            }
        }
        swap(&array[i], &array[min]);
    }
}
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
        printf("\n ");
    }
}
void main()
{

    int data1[] = {
        -2,
        6,
        9,
        8,
        2,
    };

    int size = sizeof(data1) / sizeof(data1[0]);

    selectionSort(data1, size);
    printArray(data1, size);
}