#include<iostream>
#include<string>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, hx=-1, hy=-1, wex; // heart & wrist
	int lal,ral,wl,lll,rll;
	string plate[1001];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>plate[i];
		for(int j=1;j<n;j++){
			// heart
			if(i && plate[i][j] == '*' && plate[i-1][j] == '*' && plate[i][j-1] == '*')
			{ hx = i; hy = j;}
		}
		// left & right arm
		if(i == hx){
			for (int j = 0; j < n; j++){
				// left arm
				if((j==0 && plate[i][j] == '*') || (j && plate[i][j-1] != '*' && plate[i][j] == '*'))
					lal = hy - j;
				// right arm
				if((j==n-1 && plate[i][j] == '*') || (j<n-1 && plate[i][j] == '*' && plate[i][j+1] != '*'))
					ral = j - hy;
			}
		}
	}
	// wrist
	for(int i=hx+1;i<n;i++){
		if(plate[i][hy] == '*' && plate[i+1][hy] != '*'){
			wex = i;
			wl = wex - hx;
		}
	}
	// legs
	for(int i = wex+1;i<n;i++){
		if((i == n-1 && plate[i][hy-1] == '*')||(i<n-1 && plate[i][hy-1] == '*' && plate[i+1][hy-1]))
			lll = i - wex;
		if((i == n-1 && plate[i][hy+1] == '*')||(i<n-1 && plate[i][hy+1] == '*' && plate[i+1][hy+1]))
			rll = i - wex;
	}
	cout<<hx+1<<" "<<hy+1<<"\n";
	cout <<lal<<" "<<ral<<" "<<wl<<" "<<lll<<" "<<rll<<"\n";
	return 0;
}