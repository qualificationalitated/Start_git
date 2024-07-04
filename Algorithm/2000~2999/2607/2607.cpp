#include<iostream>
#include<string>
#include<cmath>
#define ALPHA 27
using namespace std;
int main(){
	int n, orgCount[ALPHA]={0,}, ans=0;
	string origin, compare;
	cin>>n>>origin; n--;
	for(int i=0;i<origin.length();i++)
		orgCount[origin[i]-'A']++;
	while(n--){
		cin>>compare;
		int cmpCount[ALPHA] = {0,},diff=0;
		for(int i=0;i<compare.length();i++)
			cmpCount[compare[i]-'A']++;
		for(int i=0;i<ALPHA;i++)
			diff += abs(orgCount[i] - cmpCount[i]);
		if(diff < 2 || (origin.length() == compare.length() && diff == 2))
			ans++;
	}
	cout<<ans;
	return 0;
}