#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b)
{
    if(*(int *)a>*(int *)b)
        return 1;
    else if(*(int *)a<*(int *)b)
        return -1;
    else
        return 0;
}
int main()
{
    int n,list[51]={0,};
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&list[i]);
    qsort(list,n,sizeof(int),compare);
    if(n%2==1)
        printf("%d",list[n/2]*list[n/2]);
    else
        printf("%d",list[0]*list[n-1]);
    return 0;
}