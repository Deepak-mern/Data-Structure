#include <stdio.h>
#include <string.h>
struct Result
{
    char name[20];
    int maths;
    int physcis;
    int chemstry;
    int C_Program;
    int Engg_drawing;

} s[10];

int main()
{
    strcpy(s[1].name, "Deepak Prasad 1");
    s[1].maths = 16;
    s[1].physcis = 15;
    s[1].chemstry = 13;
    s[1].C_Program = 16;
    s[1].Engg_drawing = 15;
    strcpy(s[2].name, "Rohan Singh 2");
    s[2].maths = 17;
    s[2].physcis = 16;
    s[2].chemstry = 20;
    s[2].C_Program = 16;
    s[2].Engg_drawing = 15;
    strcpy(s[3].name, "Om bhatia 3");
    s[3].maths = 13;
    s[3].physcis = 16;
    s[3].chemstry = 20;
    s[3].C_Program = 16;
    s[3].Engg_drawing = 15;
    strcpy(s[4].name, "Priyanshu Singh 4");
    s[4].maths = 15;
    s[4].physcis = 16;
    s[4].chemstry = 12;
    s[4].C_Program = 16;
    s[4].Engg_drawing = 15;
    strcpy(s[5].name, "Subrato Tapsvi 5");
    s[5].maths = 15;
    s[5].physcis = 16;
    s[5].chemstry = 12;
    s[5].C_Program = 16;
    s[5].Engg_drawing = 15;
    strcpy(s[6].name, "Himanshu Singh 6");
    s[6].maths = 15;
    s[6].physcis = 16;
    s[6].chemstry = 12;
    s[6].C_Program = 16;
    s[6].Engg_drawing = 15;

    int a;
    printf("\n\n     Vivekanad Education Society\n");
    printf("      Institute Of Technology\n\n");
    printf("Internal Test -1 Sem-1 AIDS Branch Result\n\n");
    printf("Enter the student Roll no:");
    scanf("%d", &a);
    printf("\nDisplaying The result: \n");
    printf("\n");
    printf("Name Of student: %s\n\n", s[a].name);
    printf("Roll No : %d\n", a);
    printf("\n    Subjects            Marks\n\n");
    printf("1. Maths Scored:        %d/20\n", s[a].maths);
    printf("2. Physics Scored:      %d/20\n", s[a].physcis);
    printf("3. Chemistry Scored:    %d/20\n", s[a].chemstry);
    printf("4. C_Programing Scored: %d/20\n", s[a].C_Program);
    printf("5. Engg_Drawing:        %d/20\n\n", s[a].Engg_drawing);
    int b = s[a].maths + s[a].physcis + s[a].chemstry + s[a].C_Program + s[a].Engg_drawing;
    float p = (b / 100.00) * 100;
    printf("Percentage Obtained: %0.2f%%\n", p);
    
    if (b > 27)
    {
        printf("Congratulations %s  have been Passed", s[a].name);
    }
    else
    {
        printf("You Have Been Failed");
    }

    return 0;
}