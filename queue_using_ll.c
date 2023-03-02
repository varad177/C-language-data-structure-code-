#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL, *rear = NULL;

void enque(int);
void deque();
void display();

int main()
{
    int val, ch;
    do
    {
        printf("enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the value\n");
            scanf("%d", &val);
            enque(val);
            break;
        case 2:
            deque();
            break;
        case 3:
            display();
            break;
        }
    } while (ch != 4);
}
void enque(int val)
{
    struct node *nn;
    nn = malloc(sizeof(struct node));
    nn->data = val;
    nn->next = NULL;
    if (front == NULL)
    {
        front = rear = nn;
    }
    else
    {
        rear->next = nn;
        rear = nn;
    }
}

void deque()
{
    if (front == NULL)
    {
        printf("que is empty\n");
    }
    else
    {
        struct node *temp = front;
        front = front->next;
        printf("deleted element is %d\n", temp->data);
    }
}

void display()
{
    if (front == NULL)
    {
        printf("que is empty\n");
    }
    else
    {
        struct node *temp = front;
        while (temp->next != NULL)
        {

            printf("%d-->", temp->data);
            temp = temp->next;
        }
        printf("%d-->NULL\n", temp->data);
    }
}
