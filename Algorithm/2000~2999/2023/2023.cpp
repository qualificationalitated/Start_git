#include<iostream>
using namespace std;
bool isPrime(int num){
	bool is_prime = true;
	if(num<2) return false;
	else{
		for(int i=2;i<num;i++)
			if(num%i==0){
				is_prime = false;
				break;
			}
	}
	return is_prime;
}
int dfs(int start, int cnt){
	if(!cnt) cout<<start<<"\n";
	else{
		for (int i = 1; i < 10; i+=2) // 짝수는 소수가 될 수 없다
		{
			int temp = start*10+i;
			if(isPrime(temp))
				dfs(temp,cnt-1);
		}	
	}
	return 0;
}
int main(){
	int starts[4]={2,3,5,7};
	int n;
	cin>>n;
	for(int i=0;i<4;i++){
		dfs(starts[i],n-1);
	}
	return 0;
}