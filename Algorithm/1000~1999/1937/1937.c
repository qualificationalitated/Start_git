#include<stdio.h>
#define MAX 502
int map[MAX][MAX],dp[MAX][MAX]={0,};
int mx[4]={1,0,-1,0},my[4]={0,1,0,-1},n,nx,ny;
int find(int x,int y){
    if(!dp[x][y]){
        int deepest=0;
        for(int i=0;i<4;i++){
            nx=x+mx[i];
            ny=y+my[i];
            if(nx<0||ny<0||nx>=n||ny>=n||map[x][y]>=map[nx][ny])
                continue;
            int deep=find(nx,ny);
            deepest=deep>deepest?deep:deepest;
        }
        dp[x][y]=deepest+1;
    }
    return dp[x][y];
}
int main(){
    int ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&map[i][j]);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            int r=find(i,j);
            ans=ans>r?ans:r;
        }
    
    printf("%d",ans);
    return 0;
}