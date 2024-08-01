#include<iostream>
#include<vector>
using namespace std;

int sudoku[9][9];
bool isComplete = false;
vector<pair<int,int>> blankList;

bool is_possible(int r, int c, int num){
	bool possible = true;
	int rTop = (r/3)*3,cTop=(c/3)*3;
	for(int i=0;i<9;i++){
		// row && col
		if(sudoku[i][c] == num || sudoku[r][i] == num)	possible = false;
		// square
		if(sudoku[rTop+(i/3)][cTop+(i%3)]==num)			possible = false;
	}
	return possible;
}
int fill_board(int idx){
	if(isComplete) return 0;
	if(blankList.size() == idx){
		for(int r=0;r<9;r++){
			for(int c=0;c<9;c++)
				cout<<sudoku[r][c]<<" ";
			cout<<"\n";
		}
		isComplete = true;
	}
	else{
		int nr = blankList[idx].first;
		int nc = blankList[idx].second;
		for(int i=1;i<=9;i++){
			if(is_possible(nr,nc,i)){
				sudoku[nr][nc] = i;
				fill_board(idx+1);
				sudoku[nr][nc] = 0;
			}
		}
	}
	return 0;
}
int main(){
	for(int r=0;r<9;r++)
		for(int c=0;c<9;c++){
			cin>>sudoku[r][c];
			if(!sudoku[r][c]) blankList.push_back({r,c});
		}
	fill_board(0);
	return 0;
}