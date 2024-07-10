#include<iostream>
#include<vector>
#define MSUSHI 3001
using namespace std;
int main(){
	int N,d,k,c,diffPlate=1,ans=-1,sKind[MSUSHI]={0,};
	vector<int> plates;
	
	cin>>N>>d>>k>>c;
	plates.resize(N);
	sKind[c] = 1;
	for(int i=0;i<N;i++){
		cin>>plates[i];
		if(i<k){
			if(!sKind[plates[i]])	diffPlate++;
			sKind[plates[i]]++;
		}
	}
	ans = diffPlate;
	for(int i=0;i<N-1;i++){
		if(sKind[plates[i]] == 1)	diffPlate--;
		sKind[plates[i]]--;
		if(!sKind[plates[(i+k)%N]])	diffPlate++;
		sKind[plates[(i+k)%N]]++;
		if(diffPlate>ans) ans = diffPlate;
	}
	cout<<ans;
	return 0;
}