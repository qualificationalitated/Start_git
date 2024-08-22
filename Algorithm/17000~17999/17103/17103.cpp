#include<iostream>
#include<vector>
using namespace std;
vector<int> primeNumbers(int n){
	bool arr[n];
	vector<int> p_list;
	for(int i=0;i<n;i++) arr[i] = true;
	arr[0] = false; arr[1] = false;
	for(int i=2;i<n;i++)
		if(arr[i]){
			p_list.push_back(i);
			for(int j=i*2;j<n;j+=i)
				arr[j] = false;
		}
	return p_list;

}
int main(){
	int t,n;
	vector<int> p_number = primeNumbers(1000001);
	cin>>t;
	while(t--){
		int head = 0, tail = p_number.size()-1,count=0;
		cin>>n;
		while(head<=tail){
			int p_sum = p_number[head]+p_number[tail];
			if(p_sum < n)		head++;
			else if(p_sum > n)	tail--;
			else{
				count++; tail--;
			}
		}
		cout<<count<<"\n";
	}
	return 0;
}