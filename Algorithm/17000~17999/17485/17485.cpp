#include <iostream>
#define SIZE 1001
#define BIG 100002
using namespace std;
int main()
{
	int n, m, ans=__INT_MAX__;
	int input[SIZE][4], space[SIZE][3];
	cin >> n >> m;
	for (int r = 0; r < n; r++)
		if (!r)
			for (int c = 0; c < m; c++){
				cin >> input[c][3];
				for (int i = 0; i < 3; i++)
					space[c][i] = input[c][3];
			}
		else{
			for (int c = 0; c < m; c++){
				cin >> input[c][3];
				input[c][0] = input[c][3] + (0 > c - 1 ? BIG : (space[c - 1][1] < space[c - 1][2] ? space[c - 1][1] : space[c - 1][2]));
				input[c][1] = input[c][3] + (space[c][0] < space[c][2] ? space[c][0] : space[c][2]);
				input[c][2] = input[c][3] + (m - 1 < c + 1 ? BIG : (space[c + 1][0] < space[c + 1][1] ? space[c + 1][0] : space[c + 1][1]));
			}
			for (int c = 0; c < m; c++)
				for (int i = 0; i < 3; i++)
					space[c][i] = input[c][i];
		}
	for (int c = 0; c < m; c++)
			for (int i = 0; i < 3; i++)
				ans = ans<space[c][i]?ans:space[c][i];
	cout<<ans;
	return 0;
}