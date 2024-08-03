#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int mr[4]={1,0,-1,0}, mc[4]={0,1,0,-1};
int dfs(int n, string apt[],vector<int> groupNumber[],int nowR, int nowC){
	int nums=1;
	for(int i=0;i<4;i++){
		int nextR = nowR+mr[i];
		int nextC = nowC+mc[i];
		if(nextR<0||nextC<0||nextR>=n||nextC>=n) continue; // 범위
		if(apt[nextR][nextC]=='0') continue; // 빌딩여부
		if(groupNumber[nextR][nextC]) continue; // 그룹 여부
		groupNumber[nextR][nextC] = groupNumber[nowR][nowC];
		nums+=dfs(n,apt,groupNumber,nextR,nextC);
	}
	return nums;
}
int main(){
	int n,numbering=0;
	cin>>n;
	string apt[n];
	vector<int> groupNumber[n];
	vector<int> answer;
	for(int i=0;i<n;i++){
		cin>>apt[i];
		groupNumber[i].resize(n,0);
	}
	for(int r=0;r<n;r++){
		for(int c=0;c<n;c++){
			if(apt[r][c]=='1' && groupNumber[r][c]==0){
				groupNumber[r][c] = ++numbering;
				answer.push_back(dfs(n,apt,groupNumber,r,c));
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout<<numbering<<"\n";
	for(int i=0;i<numbering;i++)
		cout<<answer[i]<<"\n";
	return 0;
}