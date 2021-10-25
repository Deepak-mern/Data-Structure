#include <stdio.h>
int size = 0;

void Swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(int array[], int size, int i)
{
    if (size == 1)
    {
        printf("Singe Eement in the stack");
    }
    else
    {
        int large = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && array[l] > array[large])
            large = l;
        if (r < size && array[r] > array[large])
            large = r;

        if (large != i)
        {
            Swap(&array[i], &array[large]);
            heapify(array, size, large);
        }
    }
}

void insert(int array[], int data)
{
    if (size == 0)
    {
        array[0] = data;
        size += 1;
    }
    else
    {
        array[size] = data;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(array, size, i);
        }
    }
}
void delete (int array[], int data)
{
    int i;
    for (int i = 0; i < size; i++)
    {
        if (data == array[i])
            break;
    }
    Swap(&array[i], &array[size - 1]);
    size -= 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {

        heapify(array, size, i);
    }
}
void display(int array[], int size)
{
    
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int  main()
{
    int array1[20];
    
    insert(array1, 3);
    insert(array1, 4);
    insert(array1, 18);

    insert(array1, 9);
    insert(array1, 24);
    insert(array1, 2);

    display(array1, size);
}