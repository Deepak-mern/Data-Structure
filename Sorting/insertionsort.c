#include<stdio.h>


void insertionSort(int array[], int size){
    for (int i = 1; i < size; i++)
    {
        int key=array[i];
        int j=i-1;

        while (key<array[j] && j>=0)
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=key;
    }
    
}
void printArray(int array[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
        printf("\n ");
    }
    
}
void main(){

    int data1[]={-2,6,9,8,2,};

    int size=sizeof(data1)/sizeof(data1[0]);
    
    insertionSort(data1,size);
    printArray(data1 , size);
    }