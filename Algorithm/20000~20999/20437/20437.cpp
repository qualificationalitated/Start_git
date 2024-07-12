#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define LEN 100002
using namespace std;
int main(){
	int t, k;
	string w;
	cin >> t;
	vector<int> alpNLoc[26];
	while(t--){
		cin >> w >> k;
		int minAns = LEN, maxAns = 0;
		for(int i = 0; i<26; i++) alpNLoc[i].clear();
		for(int i = 0; i<w.length(); i++)
			alpNLoc[w[i] - 'a'].push_back(i);
		for(int i = 0; i<26; i++){
			int arrLen = (int)alpNLoc[i].size();
			if(arrLen<k)	continue;
			for(int j = 0; j<= arrLen - k; j++){
				minAns = min(minAns, alpNLoc[i][j+k-1] - alpNLoc[i][j] + 1);
				maxAns = max(maxAns, alpNLoc[i][j+k-1] - alpNLoc[i][j] + 1);
			}
		}
		if(minAns == LEN || maxAns == 0) cout << -1 << "\n";
		else cout << minAns << " " << maxAns << "\n";
	}
	return 0;
}