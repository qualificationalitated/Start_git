#include<stdio.h>
#include<stdlib.h>
#define NUM 32002
int n,m,a,b;
int *nums[NUM]={0,},nCount[NUM]={0,},inCount[NUM]={0,},used[NUM]={0,};
int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
        nums[i]=(int*)malloc(sizeof(int));
    while(m--){
        scanf("%d%d",&a,&b);
        nums[a]=(int*)realloc(nums[a],sizeof(int)*(nCount[a]+1));
        nums[a][nCount[a]++]=b;
        inCount[b]++;
    }
    while(1){
        int q[NUM]={0,},cnt=0,x;
        for (int i = 1; i <= n; i++)
            if((!inCount[i])&&(!used[i]))//들어오는 간선이 없으면
                q[cnt++]=i;
        if(!cnt)
            break;
        for (int j = 0; j < cnt; j++) {
            x=q[j];
            used[x]=1;
            printf("%d ",x);
            for (int k = 0; k < nCount[x]; k++)
                inCount[nums[x][k]]--;
        }
    }
    for (int i = 1; i <= n; i++)
        free(nums[i]);
    return 0;
}