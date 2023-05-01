#include <stdio.h>


void push(int stack[], int t, int N)
{
    int x, top;
    printf("enter the data: ");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &stack[i]);
    }
    if (top == (N - 1))
    {
        printf("overflow");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}
/*void pop()
{
    if (top == -1)
    {
        printf("stack underflow!");
    }
    else
    {
        printf("%d", stack[top]);
S
        top--;
    }
}
*/
void main()
{int stack[100], n,x;

int top = -1;

    printf("enter the size of stack:\n");
    scanf("%d", &n);
    push(stack, top, n);
     if (top == -1)
    {
        printf("stack underflow!");
    }
    else
    {
      x=stack[top];

        top--;
    }
printf("%d",x);
}

