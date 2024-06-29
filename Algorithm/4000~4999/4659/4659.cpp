#include<iostream>
#include<string>
#include<vector>
using namespace std;
int alphaChecker(char c){
	/**Vowles: 0, Else: 1 */
	return (c == 97 || c == 101 || c == 105 || c == 111 || c == 117)?0:1;
}
int main(){
	string pwd;
	bool valid = true;
	cin>>pwd;
	while(pwd.compare("end")){
		valid = true;
		int VNC[2]={0,},streakCnt=0; // Vowels & Consonants
		bool result;
		vector<bool> acResult;
		for(int i=0;i<pwd.length();i++){
			result = alphaChecker(pwd[i]);
			VNC[result]++;
			acResult.push_back(result);
			(i && acResult[i-1] == acResult[i]) ? streakCnt++ : streakCnt = 0;
			// same letter twice
			if(i && pwd[i] == pwd[i-1] && (pwd[i]!='e' && pwd[i]!='o'))
				valid = false;
			// vowel or consonants triple
			if(streakCnt == 2)
				valid = false;
			
		}
		// no vowels
		if(!VNC[0]) valid = false;
		cout<<"<"<<pwd<<"> ";
		valid?cout<<"is acceptable.\n":cout<<"is not acceptable.\n";
		cin>>pwd;
	}
	return 0;
}