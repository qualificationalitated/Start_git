#include<stdio.h>
#include<stdlib.h>
int *cardlist;
int n,m;
int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}
int upBound(int x)
{
    int head=0,tail=n-1,mid;
    while(1)
    {
        mid=(head+tail)/2;
        if(head>tail)
            if(cardlist[tail]==x)
                return tail;
            else
                return -1;
        if(cardlist[mid]<=x)
            head=mid+1;            
        else
            tail=mid-1;
    }
}
int lowBound(int x)
{
    int head=0,tail=n-1,mid;
    while(1)
    {
        mid=(head+tail)/2;
        if(head>tail)
            if(cardlist[head]==x)
                return head;
            else
                return -1;
        if(cardlist[mid]>=x)
            tail=mid-1;
        else
            head=mid+1;
    }
}
int main()
{
    int input,u;
    scanf("%d",&n);
    cardlist=(int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&cardlist[i]);
    }
    qsort(cardlist,n,sizeof(int),cmp);
    scanf("%d",&m);
    for (size_t i = 0; i < m; i++){
        scanf("%d",&input);
        u=upBound(input);
        if(u==-1)
            printf("0 ");
        else
            printf("%d ",u-lowBound(input)+1);
    }
    
    return 0;
}