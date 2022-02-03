// https://www.acmicpc.net/problem/2110
#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int n,c;
    scanf("%d %d",&n,&c);
    int house[n+1];
    for (int i = 0; i < n; i++)
        scanf("%d",&house[i]);
    qsort(house,n,sizeof(int),cmp);
    int head=1,tail=house[n-1]-house[0];
    while(head<=tail)
    {
        int start=0,mid=(head+tail)/2,count=1;//집 사이간 거리
        for (int i = start+1; i < n; i++)
            if(house[i]-house[start]>=mid){
                count++;
                start=i;
            }
        if(count<c) //가장 가까운 집간 사이의 최대값을 좀 줄여야 겟어요
            tail=mid-1;
        else // 가장 가까운 집간 사이 최대값을 좀 늘려도 될거 같아요
            head=mid+1;
    }
    printf("%d",tail);
    return 0;
}