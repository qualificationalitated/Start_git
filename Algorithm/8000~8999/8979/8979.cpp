#include<iostream>
#include<algorithm>
#define MAX 1001
using namespace std;
typedef struct{
	int num;
	int g,s,b;
	int rank;
}medal;
bool cmp(const medal a, const medal b){
	if(a.g == b.g)
		if(a.s == b.s)		return a.b>b.b;
		else 				return a.s>b.s;
	else 					return a.g>b.g;
}
int main(){
	int n,k,m;
	medal ctry[MAX];
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>m;
		cin>>ctry[m].g>>ctry[m].s>>ctry[m].b;
		ctry[m].num = m;
	}
	sort(ctry+1,ctry+n+1,cmp);
	
	ctry[1].rank = 1;
	for (int i = 2; i <= n; i++){
		ctry[i].rank = (ctry[i].g == ctry[i-1].g && ctry[i].s == ctry[i-1].s && ctry[i].b == ctry[i-1].b)?ctry[i-1].rank:i;
	}
	
	for(int i=1;i<=n;i++)
		if(ctry[i].num == k) cout<<ctry[i].rank;

	return 0;
}