#include<iostream>
#include<string>
using namespace std;
string warMap[101];
bool mapCheck[101][101]={0,};
int mr[4]={0,1,0,-1},mc[4]={1,0,-1,0};
int n,m; // 가로 n, 세로 m
int findLink(int r, int c){
	int cnt=1;
	mapCheck[r][c]=1;
	for(int i=0;i<4;i++){
		int nR=r+mr[i];
		int nC=c+mc[i];
		if(nR<0 || nC<0 || nR>=m || nC>=n || mapCheck[nR][nC])	continue;
		if(warMap[r][c]!=warMap[nR][nC]) continue;
		cnt+=findLink(nR,nC);
	}
	return cnt;
}
int main(){
	int wPower=0,bPower=0;
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>warMap[i];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			int temp=0;
			if(!mapCheck[i][j])
				temp=findLink(i,j);
			temp*=temp;
			if(warMap[i][j]=='W') wPower+=temp;
			else bPower+=temp;
		}
	}
	cout<<wPower<<" "<<bPower;
	return 0;
}