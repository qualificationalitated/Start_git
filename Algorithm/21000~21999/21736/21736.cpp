#include<iostream>
#include<algorithm>
#include<cstdio>
#define MAX 601
using namespace std;
typedef struct grid{
    int row,col;
}grid;
char map[MAX][MAX];
bool visited[MAX][MAX];
int nrow[4]={1,0,-1,0},ncol[4]={0,1,0,-1};
int n,m;
int dfs(int r,int c){
    visited[r][c]=true;
    int friends = map[r][c]=='P'?1:0;
    for(int i=0;i<4;i++){
        int nr = r+nrow[i], nc = c+ncol[i];
        if(nr<0||nc<0||nr>=n||nc>=m||map[nr][nc]=='X'||visited[nr][nc]==true)
            continue;
        friends+=dfs(nr,nc);
    }
    return friends;
}
int main(){
    int r,c,ans=0;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++){
        scanf("%s",map[i]);
        for (int j = 0; j < m; j++)
            if(map[i][j] == 'I'){
                r=i;c=j;
                visited[i][j]=true;
            }
    }
    ans = dfs(r,c);
    if(!ans)
        printf("TT");
    else
        printf("%d",ans);
    return 0;
}