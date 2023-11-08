#include<iostream>
#define MAX 101
using namespace std;
void initBalls(int *balls,int n){
    for(int i=1;i<=n;i++)
        balls[i]=i;
}
int main(){
    int n,m;
    int locA,locB,tmp;
    int balls[MAX];
    cin>>n>>m;
    initBalls(balls,n);
    while(m--){
        cin>>locA>>locB;
        tmp = balls[locA];
        balls[locA] = balls[locB];
        balls[locB] = tmp;
    }
    for (int i = 1; i <= n; i++)
        cout<<balls[i]<<" ";
    return 0;
}