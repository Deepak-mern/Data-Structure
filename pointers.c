#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, topper;
    int *classno, *classtopper;
    int **marks;
    int temp;
    printf("\n Enter no. of classes: ");
    scanf("%d", &n);
    classno = (int *)malloc(n * sizeof(int));
    classtopper = (int *)malloc(n * sizeof(int));
    marks = (int **)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("\n Enter no. of students in class %d: ", i + 1);
        scanf("%d", &classno[i]);
        temp = -1;
        marks[i] = (int *)malloc((classno[i] + 1) * sizeof(int));
        marks[i][classno[i]] = 0;
        for (int j = 0; j < *(classno + i); j++)
        {
            printf("\n Enter marks of student %d: ", j + 1);
            scanf("%d", &marks[i][j]);
            marks[i][classno[i]] += marks[i][j];
            if (temp < marks[i][j])
            {
                classtopper[i] = j;
                temp = marks[i][j];
            }
        }
        marks[i][classno[i]] /= classno[i];
    }
    temp = -1;
    for (int i = 0; i < n; i++)
    {
        printf("\n Average marks of class #%d: %d", i + 1, marks[i][classno[i]]);
        printf("\n Topper of class #%d: ", i + 1);
        printf("\n Roll no.: %d \t Marks: %d", classtopper[i] + 1, marks[i][classtopper[i]]);
        if (temp < marks[i][classtopper[i]])
            topper = i;
        putchar('\n');
    }
    printf("\n Overall  school topper is Roll no.: %d \tClass: %d", classtopper[topper] + 1, topper + 1);
    
    return 0;
}