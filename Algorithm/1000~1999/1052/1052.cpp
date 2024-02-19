#include<iostream>
#include<cmath>
#define LVL 25
using namespace std;
int arraySum(int *arr,int size){
	int sum=0;
	for(int i=0;i<size;i++){sum+=arr[i];}
	return sum;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int bLevel[LVL]={0,},ans=0;
	int n,k;
	
	cin>>n>>k; 
	bLevel[0] = n;
	
	bool doLoop = true, isError = false;
	while(doLoop){
		int minLevel=-1;

		for(int i=0;i<LVL-1;i++){
			bLevel[i+1] += bLevel[i]/2;
			bLevel[i] %= 2;
			if(minLevel == -1 && bLevel[i]) minLevel = i;	
		}
		if(arraySum(bLevel,LVL) <= k)
			doLoop = false;
		else if(minLevel == LVL-1){
			doLoop = false;
			isError = true;
		}
		else{
			bLevel[minLevel]++;
			ans+=pow(2,minLevel);
		}
	}
	isError?cout<<-1:cout<<ans;
	return 0;
}