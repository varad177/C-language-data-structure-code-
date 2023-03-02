#include <stdio.h>
int stk[25];
int top = -1;
void push();
int pop();
void push(x)
{
    top++;
    stk[top] = x;
}
int pop()
{
    return stk[top--];
}
int main()
{
    int num1, num2, ans, num;
    char postfix[100], *e;
    printf("enter postfix expression\n");
    scanf("%s", postfix);

    e = postfix;
    while (*e != '\0')
    {

        if (isdigit(*e))
        {
            num = *e - 48;
            push(num);
        }
        else
        {
            num1 = pop();
            num2 = pop();
            switch (*e)
            {
            case '/':
            {
                ans = num2 / num1;
                break;
            }

            case '*':
            {
                ans = num2 * num1;
                break;
            }

            case '+':
            {
                ans = num2 + num1;
                break;
            }

            case '-':
            {
                ans = num2 - num1;
                break;
            }
            }
            push(ans);
        }
        e++;
    }
    printf("ans=%d", pop());
}