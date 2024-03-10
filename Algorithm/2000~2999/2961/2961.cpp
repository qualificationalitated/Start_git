#include<iostream>
#include<cmath>
#define MAX 11
#define LIM 2147483647
using namespace std;
int n,ingre[MAX][2],answer=LIM;
bool selected[MAX];
int dfs(int sour,int bitter,int count,int loc){
	if(count){
		int temp = abs(sour-bitter);
		answer = answer>temp?temp:answer;
	}
	for(int i=loc;i<n;i++){
		if(selected[i] == false){
			selected[i] = true;
			dfs(sour*ingre[i][0],bitter+ingre[i][1],count+1,i);
			selected[i] = false;
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ingre[i][0]>>ingre[i][1];
	}
	dfs(1,0,0,0);
	cout<<answer;
	return 0;
}