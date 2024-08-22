#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int maxLength(string bomboni[]){
	int size = bomboni[0].size(),max_length=-1;
	string color_row,color_col;
	// 가로로 가장 긴 행렬
	for(int i=0;i<size;i++){
		int temp_length=1;
		color_row = bomboni[i][0];
		for(int j=1;j<size;j++){
			if(bomboni[i][j] == bomboni[i][j-1])
				temp_length++;
			else{
				temp_length = 1;
				color_row = bomboni[i][j];
			}
			max_length = temp_length>max_length?temp_length:max_length;
		}
	}
	// 세로로 가장 긴 행렬
	for(int i=0;i<size;i++){
		int temp_length=1;
		color_col = bomboni[0][i];
		for(int j=1;j<size;j++){
			if(bomboni[j][i] == bomboni[j-1][i])
				temp_length++;
			else{
				temp_length = 1;
				color_row = bomboni[j][i];
			}
			max_length = temp_length>max_length?temp_length:max_length;
		}
	}
	return max_length;
}
int main(){
	int n,answer=-1,temp;
	cin>>n;
	string bomboni[n];
	for(int i=0;i<n;i++)
		cin>>bomboni[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(bomboni[i][j]!=bomboni[i][j+1]){
				swap(bomboni[i][j], bomboni[i][j+1]);
				temp = maxLength(bomboni);
				swap(bomboni[i][j], bomboni[i][j+1]);
				answer = answer>temp?answer:temp;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(bomboni[j][i]!=bomboni[j+1][i]){
				swap(bomboni[j][i], bomboni[j+1][i]);
				temp = maxLength(bomboni);
				swap(bomboni[j][i], bomboni[j+1][i]);
				answer = answer>temp?answer:temp;
			}
		}
	}
	cout<<answer;
	return 0;
}