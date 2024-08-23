#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#define LIM 1003002
using namespace std;
int main(){
	// 1000000 이상의 수 이면서, 팰린드롬이면 된다는거
	// 제일 큰 팰린드롬 수는 1003001
	bool eratos[LIM]={false,};
	vector<int> pal_primes;
	int n;
	string a,b;
	// 소수 목록 만들고
	for(int i=2;i<LIM;i++){
		if(eratos[i] == false){
			// 팰린드롬 소수 찾기
			a = to_string(i);
			b = a; reverse(b.begin(),b.end());
			if(b.find(a) == 0)
				pal_primes.push_back(i);
			// 채 거르기
			for(int j=i*2;j<LIM;j+=i)
				eratos[j] = true;
		}
	}
	cin>>n;
	for(auto num : pal_primes)
		if(num>=n){
			cout<<num;
			break;
		}
	return 0;
}