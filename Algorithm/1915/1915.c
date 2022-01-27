#include<stdio.h>
#define LIM 1002
typedef struct grid{
    int x,y;
}grid;
int map[LIM][LIM]={0,},n,m;
int findMin(int x,int y){
    int tmp=map[x-1][y]<map[x][y-1]?map[x-1][y]:map[x][y-1];
    return tmp<map[x-1][y-1]?tmp:map[x-1][y-1];
}
int main()
{
    int ans=0;
    scanf("%d %d",&n,&m);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            scanf("%1d",&map[i][j]);
            if(map[i][j]){
                map[i][j]=findMin(i,j)+1;
                ans=map[i][j]>ans?map[i][j]:ans;
            }
        }
    }
    printf("%d",ans*ans);
    return 0;
}