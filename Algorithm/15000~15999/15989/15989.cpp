#include<iostream>
#define SIZE 10001
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t, n, dpArr[SIZE][4]={0,};
    for(int i=1;i<=3;i++)
        dpArr[i][i] = 1;
	for(int i=1;i<SIZE;i++)
		for(int j=1;j<=3;j++)
			for(int k=j;k<=3;k++)
				if(i+k<SIZE)
				    dpArr[i+k][k] += dpArr[i][j];
	cin>>t;
	while(t--){
		cin>>n;
		cout<<dpArr[n][1]+dpArr[n][2]+dpArr[n][3]<<"\n";
	}
	return 0;
}