#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solution(vector<int> weis,int energy){
	int max=-1,rValue;
	if(weis.size()==2)
		return energy;
	for(int i=1;i<weis.size()-1;i++){
		vector<int> mergedVec;
		for(int j=0;j<i;j++) mergedVec.push_back(weis[j]);
		for(int j=i+1;j<weis.size();j++) mergedVec.push_back(weis[j]);
		rValue = solution(mergedVec,energy+(weis[i-1]*weis[i+1]));
		if(rValue>max) max = rValue;
	}
	return max;
}
int main(){
	int n;
	cin>>n;
	vector<int> weis(n);
	for(int i=0;i<n;i++) cin>>weis[i];
	cout<<solution(weis,0);
	return 0;
}