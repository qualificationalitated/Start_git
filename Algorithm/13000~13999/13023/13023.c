#include<stdio.h>
#include<stdlib.h>
#define LIM 2002
int *friends[LIM],fCnt[LIM]={0,};
int linked[LIM]={0,};
int n,m,ans=0;
int find(int x,int depth){
    int ans=0;
    if(depth>4)
        return 1;
    linked[x]=1;
    for (int i = 0; i < fCnt[x]; i++)
        if(!linked[friends[x][i]]){
            int r=find(friends[x][i],depth+1);
            if(r) ans=1;
        }
    linked[x]=0;
    return ans;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++)
        friends[i]=(int *)malloc(sizeof(int));
    for (int i = 0; i < m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        friends[a]=(int *)realloc(friends[a],sizeof(int)*(fCnt[a]+1));
        friends[b]=(int *)realloc(friends[b],sizeof(int)*(fCnt[b]+1));
        friends[a][fCnt[a]++]=b;
        friends[b][fCnt[b]++]=a;
    }
    for (int i = 0; i < n; i++)
        if(find(i,1)){
            printf("1");
            return 0;
        }
    printf("0");
    return 0;
}