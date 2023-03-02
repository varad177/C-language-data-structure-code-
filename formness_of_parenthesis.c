#include <stdio.h>
#include <string.h>
int top = -1;
int size = 20;
int valid = 1;
int i;
int l;
char a[20];
char STK[20];
char ip;
char op;
int empty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
int full()
{
    if (top == (size - 1))
        return 1;
    else
        return 0;
}
void push(int x)
{
    if (full())
        printf("Stack is full\n");
    else
    {
        top++;
        STK[top] = x;
    }
}
int pop()
{
    int y;
    if (empty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        y = STK[top--];
    }
}
int main()
{
    printf("Enter your expression\n");
    gets(a);
    l = strlen(a);
    for (i = 0; i < l; i++)
    {
        ip = a[i];
        if (ip == '(' || ip == '{' || ip == '[')
        {
            push(ip);
        }

        if (ip == ')' || ip == '}' || ip == ']')
        {
            if (empty())
            {
                valid = 0;
            }
            else
            {
                op = pop();
                if ((ip == ')') && (op == '{' || op == '['))
                    valid = 0;
                if ((ip == '}') && (op == '[' || op == '('))
                    valid = 0;
                if ((ip == ']') && (op == '{' || op == '('))
                    valid = 0;
            }
        }
    }
    if (!empty())
    {
        valid = 0;
    }
    if (valid == 1)
    {
        printf("Entered Expression is valid\n");
    }
    else
    {
        printf("Entered expression is invalid\n");
    }
}