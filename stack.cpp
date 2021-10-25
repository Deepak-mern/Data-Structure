#include <iostream>
using namespace std;
#define MAx 20
class Stack
{
    int a[MAx];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    int push(int x)
    {

        if (top >= (MAx - 1))
        {
            cout << "Stack OverFlow\n"
                 << endl;
        }
        else
        {
            a[++top] = x;
            cout << "Element " << x << "is Pushed In Stack\n";
        }
    }

    int pop()
    {
        if (top < 0)
        {
            cout << "stack underflow\n";
        }
        else
        {
            int x = a[top--];
            return x;
        }
    }
    int peek()
    {
        if (top < 0)
        {
            cout << "stack is empty\n";
            return 0;
        }
        else
        {
            int x = a[top];
            return x;
        }
    }
    bool Isempty()
    {
        return (top < 0);
    }
    void display()
    {
        cout << "\nelements in stack\n";
        while (!Isempty())
        {
            cout << peek() << " ";
            pop();
        }
    }
};
int main()
{
    class Stack s;
    s.push(10);
    s.push(15);
    s.push(1);
    cout << s.pop() << "  popped Item is\n";
    cout << " elements in stack\n";
    // while (!s.Isempty())
    // {
    //     cout << s.peek() << " ";
    //     s.pop();
    // }
    int choice;

    int c;
    for (int i = 0; i < 5; i++)
    {

        printf("\n*****Menu****\n");
        printf("Enter The Choice\n1.Push\n2.Pop\n3.Peek\n4.IsEmpty\n5.dispaly");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the value to push");
            scanf("%d", &c);

            s.push(c);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.Isempty();
            break;
        case 5:
            s.display();
            break;

        default:
            printf("Invalid operator");
            break;
        }
    }

    return 0;
}
