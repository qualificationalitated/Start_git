#include<stdio.h>
int map[52][52],score=51,cnt=0,ans[52],list[52];
int main()
{
    int n,a,b;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            map[i][j]=51;
            if(i==j)
                map[i][j]=0;
        }   
    while(1){
        scanf("%d %d",&a,&b);
        if(a==-1&&b==-1)
            break;
        map[a][b]=1;
        map[b][a]=1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if(map[i][j]>map[i][k]+map[k][j])
                    map[i][j]=map[i][k]+map[k][j];
    for (int i = 1; i <= n; i++){
        int max=0;
        for (int j = 1; j <= n; j++)
            if(map[i][j]>max)
                max=map[i][j];
        list[i]=max;
        if(score>max)
            score=max;
    }
    for (int i = 1; i <= n; i++)
        if(list[i]==score)
            ans[cnt++]=i;
    printf("%d %d\n",score,cnt);
    for (int i = 0; i < cnt; i++)
        printf("%d ",ans[i]);
    return 0;
}