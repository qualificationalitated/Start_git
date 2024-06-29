#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	char g;
	unordered_map<string, int> player;
	string name;

	cin>>n>>g;
	while(n--){
		cin>>name;
		player[name] = true;
	}
	switch(g){
		case 'Y': // 2명
			cout<<player.size();	break;
		case 'F': // 3명
			cout<<player.size()/2;	break;
		case 'O': // 4명
			cout<<player.size()/3;	break;
	}
	return 0;
}