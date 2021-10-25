
#include <iostream>
#include <stack>
using namespace std;
bool isOperaand(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'B'))
    {
        return true;
    }
    else
        return false;
}
string pretFixToInfix(string ps)
{
    stack<string> s;
    for (int i = ps.length(); i >=0; i--)
    {
        if (isOperaand(ps[i]))
        {
            string op(1, ps[i]);
            s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op1 + ps[i] + op2 + ")");
        }
    }
    return s.top();
}
int main()
{
    string a = "+-abc";
    cout<<pretFixToInfix(a);
    return 0;
}
