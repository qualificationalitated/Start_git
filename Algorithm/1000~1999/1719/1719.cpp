#include <iostream>
#include <vector>
#define MAX 2000001
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, a, b, t;
    cin >> n >> m;
    vector<vector<int>> tMap(n+1), ans(n+1);
	for (int i = 1; i <= n; i++) {
        tMap[i].resize(n+1,MAX); tMap[i][i]=0;
        ans[i].resize(n+1);
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> t;
		tMap[a][b] = t; tMap[b][a] = t;
		ans[a][b] = b; ans[b][a] = a;
	}
	for (int k = 1; k <= n; k++) 
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++) 
				if (tMap[i][j] > tMap[i][k] + tMap[k][j]) {
					tMap[i][j] = tMap[i][k] + tMap[k][j];
					if (i != k) ans[i][j] = ans[i][k];
				}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			i == j ? cout << "- " : cout << ans[i][j]<< " ";
		cout << "\n";
	}
}