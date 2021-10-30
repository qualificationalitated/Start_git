#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}
int n,m,l[10002],a[10];
int find(int loc,int len)
{
    if (len==m){
        for (int i = 0; i < len; i++)
            printf("%d ",a[i]);
        printf("\n");
        return 0;
    }
    for (int i = loc; i < n; i++){
        a[len]=l[i];
        find(i,len+1);
        a[len]=0;
    }
    return 0;
}
int main()
{
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++)
        scanf("%d",&l[i]);
    qsort(l,n,sizeof(int),cmp);
    find(0,0);
    return 0;
}