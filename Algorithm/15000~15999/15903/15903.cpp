#include <iostream>
#include <queue> 
#include <algorithm>
using namespace std; 
typedef long long ll; 
int main() {
	int n,m;
    ll input,answer = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    cin>>n>>m; 
	for (int i = 0; i < n; i++) {
		cin >> input; 
		pq.push(input); 
	}
	while (m--) {
		ll sum=0;
        for (int i = 0; i < 2; i++){
            sum+=pq.top();
            pq.pop();
        }
        for (int i = 0; i < 2; i++)
            pq.push(sum); 
	}
	while (!pq.empty()) {
		answer += pq.top(); 
		pq.pop(); 
	}
	cout << answer; 
    return 0;
}