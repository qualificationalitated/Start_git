#include<iostream>
#include<algorithm>
#define MAX 10002
using namespace std;
typedef struct{
	int st;
	int ed;
	int srt_len;
}shortCut;
int cmp(shortCut x, shortCut y){
	return x.ed<y.ed;
}
int main(){
	shortCut li[MAX];
	int road[MAX]={0,}, srt_top=0;
	int n, tot_len;

	cin>>n>>tot_len;
	for(int i=0;i<n;i++)	cin>> li[i].st >> li[i].ed >> li[i].srt_len;
	sort(li,li+n,cmp);

	for(int i=1;i<=tot_len;i++){
		road[i]=road[i-1]+1;
		while(li[srt_top].ed==i){
			if( road[i] > road[li[srt_top].st] + li[srt_top].srt_len )
			road[i] = road[li[srt_top].st]+li[srt_top].srt_len;
			srt_top++;
		}
	}
	cout<<road[tot_len];
	return 0;
}