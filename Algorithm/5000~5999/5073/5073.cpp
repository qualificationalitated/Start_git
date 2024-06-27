#include <iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int len[3], max = -1;
	cin >> len[0] >> len[1] >> len[2];
	while (len[0] || len[1] || len[2]){
		max = -1;
		if (len[0] == len[1] && len[1] == len[2])
			cout << "Equilateral\n";
		else{
			for (int i = 0; i < 3; i++)
				max = len[i] > max ? len[i] : max;
			if(max >= len[0] + len[1] + len[2] - max) cout<<"Invalid\n";
			else{
				if (len[0] != len[1] && len[1] != len[2] && len[2] != len[0])
					cout << "Scalene\n";
				else
					cout << "Isosceles\n";
			}
		}

		cin >> len[0] >> len[1] >> len[2];
	}
	return 0;
}