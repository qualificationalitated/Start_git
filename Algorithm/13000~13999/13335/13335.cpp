#include<iostream>
#include<queue>
using namespace std;
int main(){
	int n,w,L,tot_wei=0,ans=0; // 다리를 건너는 트럭의 수, 다리의 길이, 다리의 최대 하중
	cin>>n>>w>>L;
	queue<int> bridge;
	for(int i=0;i<w;i++)
		bridge.push(0);
	int truck_wei[n+1], head=0, tail=0;
	for(int i=0;i<n;i++)
		cin>>truck_wei[i];
	while(tail<n){
		ans++;
		// 먼저 빼고
		if(bridge.front()) head++;
		tot_wei-=bridge.front();
		bridge.pop();
		// 집어넣기
		if(tot_wei + truck_wei[tail]<=L){
			tot_wei+=truck_wei[tail];
			bridge.push(truck_wei[tail++]);
		}
		else
			bridge.push(0);
	}
	while(head<tail){
		ans++;
		if(bridge.front()) head++;
		tot_wei-=bridge.front();
		bridge.pop();
	}
	cout<<ans;
	return 0;
}