#include<stdio.h>
#include<stdlib.h>
#define size sizeof(int)
int cmpU(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int cmpL(const void *a,const void *b){
    return *(int *)b-*(int *)a;
}
int main()
{
    int n,a[52],b[52],s=0,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    qsort(a,n,size,cmpU);
    qsort(b,n,size,cmpL);
    for(i=0;i<n;i++)
        s+=a[i]*b[i];
    printf("%d",s);
    return 0;
}