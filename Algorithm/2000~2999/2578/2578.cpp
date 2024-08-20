#include<iostream>
using namespace std;
struct grid{
	int r, c;
};
int is_bingo(bool checked[][5]){
	int bingo_count=0;
	// col
	for(int i=0;i<5;i++){
		bool col_bingo = true;
		for(int j=0;j<5;j++)
			if(checked[i][j] == false) col_bingo = false;
		bingo_count+=col_bingo;
	}
	// row
	for(int i=0;i<5;i++){
		bool row_bingo = true;
		for(int j=0;j<5;j++)
			if(checked[j][i] == false) row_bingo = false;
		bingo_count+=row_bingo;
	}
	// diag
	bool diag_bingo = true, rdiag_bingo = true;
	for(int i=0;i<5;i++){
		if(checked[i][i] == false) diag_bingo = false;
		if(checked[i][4-i] == false) rdiag_bingo = false;
	}
	bingo_count+=diag_bingo;
	bingo_count+=rdiag_bingo;
	
	return bingo_count;
}
int main(){
	int temp,announces[26],bingo_count=0;
	grid nums[26];
	bool checked[5][5];
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++){
			cin>>temp;
			nums[temp] = {i,j};
			checked[i][j] = false;
		}
	for(int i=0;i<25;i++)
		cin>>announces[i];
	for(int i=0;i<25;i++){
		grid loc = nums[announces[i]];
		checked[loc.r][loc.c] = true;
		if(is_bingo(checked)>=3){
			cout<<i+1<<"\n";
			break;
		}
	}
	return 0;
}