#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;

void crt_sll(int);
void display();
void ins_beg(int);
void ins_mid();
void ins_end();
void del_beg();
void del_mid(int);
void del_end();

int main()
{
    int val, ch, snv;
    printf("\n1.crt_ll\n2.display\n3.ins_beg\n4.ins__mid\n5.ins_end\n6.del_beg\n7.del_mid\n8.del_end\n");
    do
    {
        printf("enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the value\n");
            scanf("%d", &val);
            crt_sll(val);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("enter the value\n");
            scanf("%d", &val);
            ins_beg(val);
            break;
        case 4:
            printf("enter the value\n");
            scanf("%d", &val);
            printf("after which value\n");
            scanf("%d", &snv);
            ins_mid(val, snv);
            break;
        case 5:
            printf("enter the value\n");
            scanf("%d", &val);
            ins_end(val);
            break;
        case 6:
            del_beg();
            break;
        case 7:
            printf("value to deleted\n");
            scanf("%d", &snv);
            del_mid(snv);
            break;
        case 8:
            del_end();
            break;
        }
    } while (ch != 9);
}

void crt_sll(int val)
{
    struct node *nn, *tn;
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
        while (tn->next != NULL)
        {
            tn = tn->next;
        }
        tn->next = nn;
    }
}

void display()
{
    struct node *tn;
    if (start == NULL)
    {
        printf("LL is empty\n");
        return;
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

void ins_beg(int val)
{
    struct node *nn;
    nn = malloc(sizeof(struct node));
    nn->data = val;
    nn->next = start;
    start = nn;
}

void ins_mid(int val, int snv)
{
    struct node *nn, *tn;
    tn = start;
    while (tn != NULL)
    {
        if (tn->data == snv)
        {
            nn = malloc(sizeof(struct node));
            nn->data = val;
            nn->next = tn->next;
            tn->next = nn;
            return;
        }
        tn = tn->next;
    }
}

void ins_end(int val)
{
    struct node *tn, *nn;
    nn = malloc(sizeof(struct node));
    nn->data = val;
    nn->next = NULL;
    tn = start;
    while (tn->next != NULL)
    {
        tn = tn->next;
    }
    tn->next = nn;
}

void del_beg()
{
    start = start->next;
}

void del_mid(int snv)
{
    struct node *tn;
    tn = start;
    while (tn != NULL)
    {
        if (tn->next->data == snv)
        {
            tn->next = tn->next->next;
            return;
        }
        tn = tn->next;
    }
}

void del_end(int val)
{
    struct node *tn;
    tn = start;
    while (tn != NULL)
    {
        if (tn->next->next == NULL)
        {
            tn->next = NULL;
        }
        tn = tn->next;
    }
}
