#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;

void push(int);
void pop();
void display();

int main()
{
    int ch, val;
    do
    {

        printf("enter the choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the value\n");
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

void push(int val)
{
    struct node *nn;
    nn = malloc(sizeof(struct node));
    nn->data = val;
    if (top == NULL)
    {
        nn->next = NULL;
    }
    else
    {
        nn->next = top;
    }
    top = nn;
}

void pop()
{
    if (top == NULL)
    {
        printf("stk is empty");
    }
    else
    {
        struct node *temp = top;
        printf("deleted element is %d\n", temp->data);
        top = temp->next;
    }
}
void display()
{
    if (top == NULL)
    {
        printf("stk is empty");
    }
    else
    {
        struct node *temp = top;
        while (temp->next != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->next;
        }
        printf("%d-->NULL\n", temp->data);
    }
}
