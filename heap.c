#include <stdio.h>

int size = 0;
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void heapify(int array[], int size, int i)
{

    if (size == 1)
    {
        printf("Single Element in the array cannot be heap");
    }
    else
    {
        int large = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && array[l] > array[large])
            large = 1;
        if (r < size && array[r] > array[large])
            large = r;
        if (large != i)
        {
            swap(&array[i], &array[large]);
            heapify(array, size, large);
        }
    }
}
void insert(int array[], int newnum)
{
    if (size == 0)
    {
        array[0] = newnum;
        size++;
    }
    else
    {
        array[size] = newnum;
        size++;
        for (int i = size / 2 - 1; i > +0; i--)
        {
            heapify(array, size, i);
        }
    }
}
void delete (int array[], int num)
{
    int i;
    for (int i = 0; i < size; i++)
    {
        if (num == array[i])
            ;
        break;
    }
    swap(&array[i], &array[size - 1]);
    size -= 1;
    for (int i = size / 2 - 1; i >= 0; i--)
        ;
    {
        heapify(array, size, i);
    }
}
void print(int array[], int size){
    for(int i =0;i<size; i++){
        printf("%d", array[i]);
        printf("\n");

    }
}
int main(){

    int array[10];

    insert(array,3);
    insert(array,4);
    insert(array,5);
    insert(array,6);
    insert(array,7);
    printf("max-haep: ");
    print(array, size);
    delete(array, 4);
    printf("afetere ");
      print(array, size);
    

    return 0;
}
