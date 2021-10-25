#include <stdio.h>
#include <string.h>
#define MAX 100
int st[MAX];
int choice, n, top, x;
 top = -1;
// void push();
// void pop();
char push(char c)
{

    st[++top] = c;
}
char pop()
{


        return (st[top--]);
   
}
char top()
{
    return st[top];
}
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
void infixToPostfix(char s[])
{

   
    char result[100];
    for (int i = 0; i < strlen(s); i++)
    {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        else if (c == '(')
            st.push('(');

        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    cout << result << endl;
}

int main()
{
 
    char exp[]= "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}