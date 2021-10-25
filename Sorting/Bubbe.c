#include <stdio.h>

void bubbleSort(int array[],int size){
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (array[j]>array[j+1])
            {
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
            
        }
        
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
    
    bubbleSort(data1,size);
    printArray(data1 , size);
    }