#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct virus{
    int num;
    int r;
    int c;
    virus(int x,int y,int z) : num(x), r(y), c(z){} // 구조체 생성자
};
bool cmp(virus x, virus y){
    return x.num < y.num; // 오름차순 정렬
}

int map[202][202]={0,};
int movR[4]={1,0,-1,0},movC[4]={0,1,0,-1};

vector<virus> input;
queue<virus> que;

int main(){
    int n,k,s,x,y;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
            if(map[i][j])
                input.push_back(virus(map[i][j],i,j));
        }
    }
    sort(input.begin(),input.end(),cmp);
    for(int i=0;i<input.size();i++) que.push(input[i]);

    cin>>s>>x>>y;
    while(s-- && !que.empty()){
        int size = que.size();
        for(int i=0;i<size;i++){
            virus now = que.front();
            for(int i=0;i<n;i++){
                int nr = now.r+movR[i];
                int nc = now.c+movC[i];
                if(nr<0 || nc<0 || nr>=n || nc>=n || map[nr][nc])
                    continue;
                map[nr][nc] = now.num;
                que.push(virus(now.num,nr,nc));
            }
            que.pop();
        }
    }
    
    cout<<map[x-1][y-1];
    return 0;
}