#include<stdio.h>
int HW[102][102]={0,},CK[102][102]={0,},ans=0,s;
int mx[4]={0,1,0,-1},my[4]={1,0,-1,0},n,m,k,r,c;
int find(int x,int y){
    CK[x][y]=1;
    ans=s>ans?s:ans;
    for (int i = 0; i < 4; i++){
        int nx=x+mx[i],ny=y+my[i];
        if(0<nx&&nx<=n&&0<ny&&ny<=m&&HW[nx][ny]==1&&CK[nx][ny]==0){
            s++;
            find(nx,ny);
        }
    }
    return 0;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    while(k--){
        scanf("%d%d",&r,&c);
        HW[r][c]=1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if(!CK[i][j]&&HW[i][j]==1){
                s=1;
                find(i,j);
            }
    printf("%d",ans);
    return 0;
}