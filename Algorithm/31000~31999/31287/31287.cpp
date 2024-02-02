#include<iostream>
#include<string>
#define LIM 2001
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int n,k;
    int curr_row=0,curr_col=0;
    bool answer = false;
    string move;
    cin>>n>>k;
    cin>>move;
    if(k>n/2)
        k = n/2;

    while(k--){
        for(char x : move){
            switch(x){
                case 'U':
                    curr_col++;
                    break;
                case 'D':
                    curr_col--;
                    break;
                case 'R':
                    curr_row++;
                    break;
                case 'L':
                    curr_row--;
                    break;
                default:
                    break;
            }
            if(curr_col == 0 && curr_row == 0){
                answer = true;
                break;
            }
        }
    }
    answer ? cout<<"YES" : cout<<"NO";
    return 0;
}