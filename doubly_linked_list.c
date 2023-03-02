#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start = NULL, *last;

void crt_dll(int);
void display();
void display2();
void ins_beg(int);

void main()
{
    int ch, val;

    do
    {
        printf("enter your ch\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter your value\n");
            scanf("%d", &val);
            crt_dll(val);
            break;
        case 2:
            display();
            break;
        case 3:
            display2();
            break;
        case 4:
            printf("enter your value\n");
            scanf("%d", &val);
            ins_beg(val);
            break;
        }
    } while (ch != 5);
}

void crt_dll(int val)
{
    struct node *tn, *nn;
    nn = malloc(sizeof(struct node));
    nn->data = val;
    nn->next = NULL;
    if (start == NULL)
    {

        start = nn;
        nn->prev = NULL;
    }
    else
    {
        tn = start;
        while (tn->next != NULL)
        {
            tn = tn->next;
        }
        tn->next = nn;
        nn->prev = tn;
    }
    last = nn;
}

void display()
{
    struct node *tn;
    if (start == NULL)
    {
        printf("not valid");
    }
    else
    {
        tn = start;
        while (tn != NULL)
        {
            printf("%d\n", tn->data);
            tn = tn->next;
        }
    }
}

void display2()
{
    struct node *tn;
    if (start == NULL)
    {
        printf("not valid");
    }
    else
    {
        tn = last;
        while (tn != NULL)
        {
            printf("%d\n", tn->data);
            tn = tn->prev;
        }
    }
}

void ins_beg(int val)
{
    struct node *nn;
    nn = malloc(sizeof(struct node));
    nn->data = val;
    nn->next = start;
    nn->prev = NULL;
    start->prev = nn;
    start = nn;
}
