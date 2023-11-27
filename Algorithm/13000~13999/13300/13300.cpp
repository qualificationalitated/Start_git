#include <iostream>
using namespace std;
int main(int argc, char**argv) {
	
	int arr[2][7]={0};
	int N, K, res=0;
    int S, G;
	cin >> N >> K;
	for(int i=0; i<N; i++){
		cin >> S >> G;
		arr[S][G]++;
	}
	for(int i=0; i<2; i++){
		for(int j=1; j<7; j++){
			if(arr[i][j]){
				res += arr[i][j]/K;
				if(arr[i][j]%K)
					res++;
			}
		}
    }
	cout << res;
	return 0;
}