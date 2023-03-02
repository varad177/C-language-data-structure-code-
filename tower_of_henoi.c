#include <stdio.h>
int main()
{
    int nd;
    printf("enter the number of disk\n");
    scanf("%d", &nd);
    toh(nd, 'A', 'B', 'C');
}
void toh(int nd, char s, char d, char a)
{
    static int step = 0;

    if (nd == 1)
    {
        printf("step no %d moves disk from %c to %c\n", ++step, s, d);
    }
    else
    {
        toh(nd - 1, s, a, d);
        printf("step no %d moves disk from %c to %c\n", ++step, s, d);
        toh(nd - 1, a, d, s);
    }
}