#include<stdio.h>
int w,h,map[52][52];
int mx[8]={1,1,0,-1,-1,-1,0,1},my[8]={0,1,1,1,0,-1,-1,-1};
int find(int x,int y)
{
    map[x][y]=0;
    for (int i = 0; i < 8; i++){
        int nx=x+mx[i],ny=y+my[i];
        if(0<=nx&&0<=ny&&nx<h&&ny<w&&map[nx][ny]==1)
            find(nx,ny);
    }
    return 0;
}
int main()
{
    while(1){
        int count=0;
        scanf("%d %d",&w,&h);
        if(w==0&&h==0)
            return 0;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                scanf("%d",&map[i][j]);
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if(map[i][j]==1){
                    count++;
                    find(i,j);
                }
        printf("%d\n",count);
    }
    return 0;
}