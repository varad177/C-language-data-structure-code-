#include <stdio.h>
int size = 5;
int stk[5];
int top = -1;

void push(int val)
{

    if (top == (size - 1))
    {
        printf("stk is full\n");
    }
    else
    {
        top++;
        stk[top] = val;
    }
}

void pop()
{
    int val;
    if (top == (-1))
    {
        printf("stk is empty\n");
    }
    else
    {
        val = stk[top];
        printf("the poped value is %d\n", val);
        top--;
    }
}

void display()
{
    if (top == (-1))
    {
        printf("stk is empty\n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stk[i]);
        }
    }
}
int main()
{
    int val;
    int ch;
    do
    {
        printf("enter ch\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter value\n");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        }
    } while (ch != 4);
}
