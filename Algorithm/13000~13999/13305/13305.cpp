#include<iostream>
#include<vector>
#define MAX 100001
using namespace std;
using ll = long long;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,dist;
	ll cheapOil,cost,nextOil;
	vector<int> cummDist,stt;
	cin>>n;
	// 누적 거리
	for(int i=0;i<n-1;i++)	{
		cin>>dist; 
		if(i)
			cummDist.push_back(dist + cummDist[i-1]);
		else
			cummDist.push_back(dist);
	}
	cin>>cheapOil;
	cost = cheapOil * cummDist[n-2];
	for(int i=1;i<n;i++){
		cin>>nextOil;
		if(nextOil < cheapOil){
			cost -= (cummDist[n-2] - cummDist[i-1]) * (cheapOil - nextOil);
			cheapOil = nextOil;
		}
	}
	cout<<cost;
	return 0;
}