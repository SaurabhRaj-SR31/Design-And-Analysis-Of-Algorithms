#include<iostream>
#include<math.h>
#include<stack>
using namespace std;
float scanNum(char ch)
{
    int value;
    value = ch;
    return float(value-'0');
}
int isOperator(char ch)
{
    if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' || ch == '^')
        return 1;
    return -1;
}
int isOperand(char ch)
{
    if(ch >= '0' && ch <= '9')
        return 1;
    return -1;
}
float operation(int a, int b, char op)
{

    if(op == '+')
        return b+a;
    else if(op == '-')
        return b-a;
    else if(op == '*')
        return b*a;
    else if(op == '/')
        return b/a;
    else if(op == '^')
        return pow(b,a);
    else
        return -1;
}
float postfixEval(string postfix)
{
    int a, b;
    stack<float> stk;
    string::iterator it;
    for(it=postfix.begin(); it!=postfix.end(); it++)
    {

        if(isOperator(*it) != -1)
        {
            a = stk.top();
            stk.pop();
            b = stk.top();
            stk.pop();
            stk.push(operation(a, b, *it));
        }
        else if(isOperand(*it) > 0)
        {
            stk.push(scanNum(*it));
        }
    }
    return stk.top();
}
main()
{
    char post[50] ;
    cout<<"enter your postfix expression:"<<endl;
    gets(post);
    fflush(stdin);
    cout <<"value: "<<postfixEval(post);
}