#include<stdio.h>
#include<stdlib.h>
typedef struct array{
    int value;
    int loc;
} array;
int cmp(const void *a,const void *b)
{
    array *A=(array *)a;
    array *B=(array *)b;
    return A->value-B->value;
}
int main()
{
    int n,count=0;
    array *list,*sort;
    scanf("%d",&n);
    list=(array*)malloc(sizeof(array)*n);
    sort=(array*)malloc(sizeof(array)*n);
    for (int i = 0; i < n; i++){
        scanf("%d",&list[i].value);
        sort[i].value=list[i].value;
        sort[i].loc=i;
    }
    qsort(sort,n,sizeof(array),cmp);
    list[sort[0].loc].loc=0;
    for (int i = 1; i < n; i++)
    {
        if(sort[i].value>sort[i-1].value)
            count++;
        list[sort[i].loc].loc=count;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",list[i].loc);
    }
    return 0;
}