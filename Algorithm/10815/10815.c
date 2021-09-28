#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int main()
{
    int n,m,input,i;
    scanf("%d",&n);
    int list[n+1];
    for(i=0;i<n;i++)
        scanf("%d",&list[i]);
    qsort(list,n,sizeof(int),cmp);
    scanf("%d",&m);
    int answer[m+1];
    for(i=0;i<m;i++)
    {
        scanf("%d",&input);
        int head=0,tail=n-1,mid,check=0;
        while(head<=tail){
            mid=(head+tail)/2;
            if(list[mid]==input){
                check=1;
                break;
            }
            else if(list[mid]<input)
                head=mid+1;
            else
                tail=mid-1;
        }
        answer[i]=check;
    }
    for(i=0;i<m;i++)
        printf("%d ",answer[i]);
    return 0;
}