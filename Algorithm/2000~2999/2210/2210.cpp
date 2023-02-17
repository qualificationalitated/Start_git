#include<iostream>
#include<vector>
using namespace std;
#define MAX 1000000
string map[6][6];
bool check[MAX]={0,};
int mr[4]={1,0,-1,0},mc[4]={0,1,0,-1},cnt=0;
int make_num(int r, int c,string str);

int main(){
    for(int i=0;i<MAX;i++) // init
        check[i] = true;
    
    for(int i=0;i<5;i++) // input
        for(int j=0;j<5;j++)
            cin>>map[i][j];
    
    for(int i=0;i<5;i++) // seek number
        for(int j=0;j<5;j++)
            make_num(i,j,map[i][j]);

    cout<<cnt;
    return 0;
}
int make_num(int r, int c,string str){
    if(str.length() == 6) { // 
        cnt+= check[stoi(str)];
        check[stoi(str)] = false;
    }
    else{
        int nr,nc;
        for(int i=0;i<4;i++){
            nr = r + mr[i]; nc = c + mc[i];
            if(nr<0 || nc<0 || nr>=5 || nc >= 5)
                continue;
            make_num(nr,nc,str+map[nr][nc]);
        }
    }
    return 0;
}