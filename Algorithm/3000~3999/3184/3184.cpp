// https://www.acmicpc.net/problem/3184
#include<cstdio>
#include<iostream>
#include<vector>
#define MAX 252
using namespace std;

int row, col;
char map[MAX][MAX];
bool check[MAX][MAX]={0,};
int nR[4]={0,1,0,-1},nC[4]={1,0,-1,0};

pair<int,int> findArea(int x,int y){
	pair<int,int> temp;
	int wC=0,lC=0;

	check[x][y]=1;
	if(map[x][y]=='v') wC++;
	else if(map[x][y]=='o') lC++;

	for(int i=0;i<4;i++){
		int nx=x+nR[i], ny=y+nC[i];
		if(nx<0 || ny<0 || nx >= row || ny >= col)	continue;
		if(check[nx][ny] || map[nx][ny]=='#')	continue;
		temp = findArea(nx,ny);
		wC+=temp.first; lC+=temp.second;
	}

	return make_pair(wC,lC);
}
pair<int,int> solve(){
	pair<int,int> temp;
	int wolf,lamb;
	int tot_wolf=0,tot_lamb=0;

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(check[i][j] || map[i][j]=='#') continue;
			
			temp = findArea(i,j);
			wolf=temp.first;
			lamb=temp.second;
			if(wolf<lamb)
				tot_lamb+=lamb;
			else
				tot_wolf+=wolf;
		}
	}
	return make_pair(tot_lamb,tot_wolf);
}
int main(){
	// ios_base::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);

	pair<int,int> ans;
	scanf("%d %d",&row,&col);
	for(int i=0;i<row;i++)
		scanf("%s",map[i]);
	ans=solve();
	printf("%d %d",ans.first,ans.second);
}