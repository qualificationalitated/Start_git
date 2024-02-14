#include <iostream>
#include <queue>
#include <vector>
typedef long long ll;
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,input;
	ll temp, answer=0;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	cin>>n;
	while(n--){
		cin>>input;
		pq.push(input);
	}
	while(pq.size()>1){
		temp = 0;
		temp += pq.top(); pq.pop();
		temp += pq.top(); pq.pop();
		answer+=temp;
		pq.push(temp);
	}
	cout<<answer;
	return 0;
}