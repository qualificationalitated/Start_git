#include<stdio.h>
#include<stdlib.h>
int *arr,maxLen=0;
int main()
{
    int n,m;
    scanf("%d",&n);
    arr=(int *)malloc(sizeof(int)*(n+1));
    arr[0]=0;
    for (int i = 1; i <= n; i++){
        int j=0;
        scanf("%d",&m);
        if(arr[maxLen]<m)
            arr[++maxLen]=m;
        else{
            int start=1,mid,end=maxLen;
            while(start<=end){
                mid=(start+end)/2;
                if(arr[mid]<m)
                    start=mid+1;
                else
                    end=mid-1;
            }
            arr[end+1]=m;
        }
    }
    printf("%d",maxLen);
    free(arr);
    return 0;
}