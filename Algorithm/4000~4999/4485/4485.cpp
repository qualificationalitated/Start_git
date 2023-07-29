#include<iostream>
#include<queue>
#include<vector>
#define LIM 126
#define INF 2147483647
using namespace std;
struct room{
    int row,col,cost;
    room(int Cst,int r, int c) : row(r), col(c), cost(Cst){}
    // 비용이 낮은것이 우선순위를 차지한다
    bool operator<(const room x) const {
        return this->cost > x.cost;
    }
};
int minCost[LIM][LIM],nx[4]={1,0,-1,0},ny[4]={0,1,0,-1};
int caveMap[LIM][LIM];
int dijkstra(int sRow,int sCol,int n){
    priority_queue<room> pq;
    pq.push(room(caveMap[sRow][sCol],sRow,sCol));
    minCost[sRow][sCol] = caveMap[sRow][sCol];
    while(!pq.empty()){
        room nRoom = pq.top();
        pq.pop();
        if(nRoom.cost>minCost[nRoom.row][nRoom.col])
            continue;
        for(int i=0;i<4;i++){
            int nxRow = nRoom.row+nx[i];
            int nxCol = nRoom.col+ny[i];
            int nxCost = nRoom.cost+caveMap[nxRow][nxCol];
            if(nxRow<0||nxCol<0||nxRow>=n||nxCol>=n)
                continue;
            if(nxCost<minCost[nxRow][nxCol]){
                minCost[nxRow][nxCol] = nxCost;
                pq.push(room(nxCost,nxRow,nxCol));
            }
        }
    }
    return 0;
}
int main(){
    int n,cnt=1;
    cin>>n;
    while(n){
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++){
                cin>>caveMap[i][j];
                minCost[i][j]=INF;
            }
        dijkstra(0,0,n);
        cout<<"Problem "<<cnt++<<": "<<minCost[n-1][n-1]<<"\n";
        cin>>n;
    }
    return 0;
}