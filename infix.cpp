#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}
int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

string infixToPostFix(string infix)
{
    infix = '(' + infix + ')';
    int len = infix.length();
    stack<char> char_stack;
    string output;
    for (int i = 0; i < len; i++)
    {
        /* code */

        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];
        else if (infix[i] == '(')
            char_stack.push('(');
        else if (infix[i] == ')')
            while (char_stack.top() != '(')
            {
                output += char_stack.top();
                char_stack.pop();
            }
        else
        {
            if (isOperator(char_stack.top()))
            {
                if (infix[i] == '^')
                {
                    while (getPriority(infix[i]) <= getPriority(char_stack.top()))
                    {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                }
                else
                {
                    while (getPriority(infix[i]) < getPriority(char_stack.top()))
                    {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                }
                char_stack.push(infix[i]);
            }
        }
    }
    return output;
}

int main()
{
    string s = ("x+y*t+z/w+u");
    cout << infixToPostFix(s) << std::endl;
    return 0;
}