#include<stdio.h>
void swap(  int arr[],int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void waveSort(int arr[],int n){
    for (int i = 0; i < n; i+=2)
    {
        if (arr[i]>arr[i-1])
        {
            swap(arr,&arr[i],&arr[i-1]);
        }
        if (arr[i]>arr[i+1] && i<=n-2)
        {
            swap(arr, &arr[i],&arr[i+1]);
        }
        
        
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

    waveSort(data1, size);
    printArray(data1, size);
}