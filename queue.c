#include <stdio.h>
int que[5];
int size = 5;
int rear = -1;
int front = 0;

void enque(int val)
{
    if (rear == (size - 1))
    {
        printf("q is full\n");
    }
    else
    {
        rear++;
        que[rear] = val;
    }
}
void deque()
{
    int val;

    if (rear == -1 || front > rear)
    {
        printf("q is empty \n");
    }
    else
    {
        val = que[front];
        front++;
        printf("%d\n", val);
    }
}

void display()
{
    if (rear == -1 || front > rear)
    {
        printf("que is empty \n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d\n", que[i]);
        }
    }
}
int main()
{
    int val, ch;
    do
    {
        printf("enter ch\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter value\n");
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
