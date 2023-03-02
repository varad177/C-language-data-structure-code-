#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;

void crt_csll(int);
void ins_beg(int);
void display();

void main()
{
    int ch, val;

    do
    {
        printf("enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter your value\n");
            scanf("%d", &val);
            crt_csll(val);

            break;
        case 2:
            printf("enter your value\n");
            scanf("%d", &val);
            ins_beg(val);

            break;
        case 3:
            display();
            break;
        }
    } while (ch != 4);
}

void crt_csll(int val)
{
    struct node *tn, *nn;
    nn = malloc(sizeof(struct node));
    nn->data = val;
    nn->next = NULL;
    if (start == NULL)
    {
        start = nn;
    }
    else
    {
        tn = start;
        while (tn->next != start)
        {
            tn = tn->next;
        }
        tn->next = nn;
    }
    nn->next = start;
}

void ins_beg(int val)
{
    struct node *tn, *nn;
    nn = malloc(sizeof(struct node));
    nn->data = val;
    nn->next = start;
    tn = start;
    while (tn->next != start)
    {
        tn = tn->next;
    }
    tn->next = nn;
    start = nn;
}

void display()
{
    struct node *tn;
    if (start == NULL)
    {
        printf("not valid");
        return;
    }
    else
    {
        tn = start;
        while (tn->next != start)
        {
            printf("%d\n", tn->data);
            tn = tn->next;
        }
        printf("%d\n", tn->data);
    }
}
