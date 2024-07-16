#include<iostream>
#include<string>
using namespace std;
int main(){
	string input;
	char TTT[3][3];
	while(1){
		int OCnt=0, XCnt=0;
		bool XWin = false, OWin = false, isValid = false;
		cin>>input;
		if(input[0]=='e') break;
		for(int i=0;i<9;i++){
			if(input[i] == 'O') OCnt++;
			else if(input[i] == 'X') XCnt++;
			TTT[i/3][i%3]=input[i];
		}
		for(int i=0;i<3;i++){
			// 가로 빙고
			if(TTT[i][0] == TTT[i][1] && TTT[i][1] == TTT[i][2])
				if(TTT[i][0]=='X')		XWin = true;
				else if(TTT[i][0]=='O')	OWin = true;
			// 세로 빙고
			if(TTT[0][i] == TTT[1][i] && TTT[1][i] == TTT[2][i])
				if(TTT[0][i]=='X')		XWin = true;
				else if(TTT[0][i]=='O')	OWin = true;
		}
		// 대각선 빙고
		if((TTT[0][0]==TTT[1][1] && TTT[1][1] == TTT[2][2]) || 
			(TTT[0][2]==TTT[1][1] && TTT[1][1] == TTT[2][0]))
			if(TTT[1][1]=='X')		XWin = true;
			else if(TTT[1][1]=='O')	OWin = true;
		// x가 승리 && O보다 X가 1개 더 많음
		if(XWin && !OWin && XCnt==OCnt+1)				isValid = true;
		// O가 승리 && O와 X가 같음
		else if(!XWin && OWin && XCnt==OCnt)			isValid = true;
		// 둘다 못이김 && 순서에 맞게 동작
		else if(!XWin && !OWin && XCnt==5 && OCnt==4)	isValid = true;
		isValid?cout<<"valid\n":cout<<"invalid\n";
	}
	return 0;
}