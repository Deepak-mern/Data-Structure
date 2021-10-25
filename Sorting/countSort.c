#include <stdio.h>

void countSort(int arr[], int size)
{
    int output[10];
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int count[10];
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
        printf("\n ");
}
void main()
{

    int data1[] = {
        4,8,9,9,2
        
    };

    int size = sizeof(data1) / sizeof(data1[0]);

    countSort(data1, size);
    printArray(data1, size);
}
