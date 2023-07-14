#include<iostream>
#include<algorithm>
#define MAX 1001
using namespace std;
typedef struct grid{
    int row,col;
}grid;
int map[MAX][MAX]={0,},dist[MAX][MAX]={0,};
int nrow[4]={1,0,-1,0},ncol[4]={0,1,0,-1};
grid que[MAX*MAX],nwGrd,nxGrd;
int main(){
    int n,m,head=0,tail=1;
    cin>>n>>m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin>>map[i][j];
            if(map[i][j])
                dist[i][j]=-1; // 방문여부 초기화
            if(map[i][j]==2){
                que[0].row=i;
                que[0].col=j;
                dist[i][j]=0;
            }
        }
    }
    while(head!=tail){
        nwGrd=que[head++];
        for (int i = 0; i < 4; i++)
        {
            nxGrd.row = nwGrd.row + nrow[i];
            nxGrd.col = nwGrd.col + ncol[i];
            if(nxGrd.row<0 || nxGrd.row>=n || nxGrd.col<0 || nxGrd.col>=m || map[nxGrd.row][nxGrd.col]==0 || dist[nxGrd.row][nxGrd.col]!=-1)
                continue;
            dist[nxGrd.row][nxGrd.col] = dist[nwGrd.row][nwGrd.col]+1;
            que[tail++]=nxGrd;
        }
        
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout<<dist[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}