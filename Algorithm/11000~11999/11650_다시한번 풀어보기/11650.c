#include<stdio.h>
#include<stdlib.h>
struct vector{
    int x,y;
};
struct vector arr[100001];
int merge(struct vector *input,int start,int mid,int end)
{
    int i,j,k;
    i=start;
    j=mid+1;
    k=start;
    while(i<=mid&&j<=end)
    {
        if(input[i].x<input[j].x)
            arr[k++]=input[i++];
        else if(input[i].x>input[j].x)
            arr[k++]=input[j++];
        else
        {
            if(input[i].y<input[j].y)
                arr[k++]=input[i++];
            else if(input[i].y>input[j].y)
                arr[k++]=input[j++];
        }
    }
    if(i<=mid)
    {
        while(i<=mid)
            arr[k++]=input[i++];
    }
    else
    {
        while(j<=end)
            arr[k++]=input[j++];
    }
    for (k=start;k<=end;k++)
        input[k]=arr[k];  
    return 0;
}
int mergeSort(struct vector *input,int start,int end)
{
    int mid;
    if(start<end)
    {
        mid=(start+end)/2;
        mergeSort(input,start,mid);
        mergeSort(input,mid+1,end);
        merge(input,start,mid,end);
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    struct vector *input = (struct vector*)malloc(sizeof(struct vector)*n);
    for (int i=0;i<n;i++)
        scanf("%d %d",&input[i].x,&input[i].y);
    mergeSort(input,0,n-1);
    for (int i=0;i<n;i++)
        printf("%d %d\n",input[i].x,input[i].y);
    return 0;
}