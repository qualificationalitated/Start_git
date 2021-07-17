#include<stdio.h>
#include<stdlib.h>
int list[100001]={0,};
int compare(const void *a,const void *b)
{
    if(*(int *)a>*(int *)b)
        return 1;
    else if (*(int *)a<*(int *)b)
        return -1;
    else
        return 0;
    
}
int find(int n,int find)
{
    int minRange=0,maxRange=n-1;
    int center=0;
    while(minRange<=maxRange)
    {
        center=(minRange+maxRange)/2;
        if (list[center]==find){
            printf("1");
            return 1;
        }
        else if(list[center]>find)
            maxRange=center-1;
        else
            minRange=center+1;
    }
    printf("0");
    return 0;
}
int main()
{
    int n,m,l;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&list[i]);
    qsort(list,n,sizeof(int),compare);
    scanf("%d",&m);
    for (int i=0;i<m;i++)
    {
        scanf("%d",&l);
        find(n,l);
    }
    return 0;
}