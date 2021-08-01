#include<stdio.h>
int list[1000001];
int main()
{
    int head=1,tail;
    scanf("%d",&tail);
    for (int i = 1; i <= tail; i++)
    {
        list[i]=i;
    }
    while(head<tail)
    {
        list[++tail]=list[++head];
        head++;
    }
    printf("%d",list[tail]);
    return 0;
}