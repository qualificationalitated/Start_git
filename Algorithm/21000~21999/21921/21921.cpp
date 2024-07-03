#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,x,visitor,maxVisit = 0, termCount=0;
	vector<int> vList,vAcumm;
	cin>>n>>x;
	for(int i=0;i<n;i++){
		cin>>visitor; vList.push_back(visitor);
		vAcumm.size() ? vAcumm.push_back(visitor + vAcumm[i-1]) : vAcumm.push_back(visitor);
		if(i>=x)	vAcumm[i] -= vList[i-x];
		maxVisit = maxVisit > vAcumm[i] ? maxVisit : vAcumm[i];
	}
	for(int i=0;i<vAcumm.size();i++)
		if(vAcumm[i] == maxVisit) termCount++;
	maxVisit? cout<<maxVisit<<"\n"<<termCount : cout<<"SAD";
	return 0;
}