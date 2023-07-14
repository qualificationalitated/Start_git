#include<iostream>
#include<algorithm>
using namespace std;
typedef struct line{
    int dir;
    int len;
}line;
int main(){
    line list[6];
    int n,dirCnt[5]={0,},big=1,small=1;
    cin>>n;
    for(int i=0;i<6;i++){
        cin>>list[i].dir>>list[i].len;
        dirCnt[list[i].dir]++;
    }
    for(int i=0;i<6;i++)
        if(dirCnt[list[i].dir]==1) // 긴 변 & 긴 높이
            big*=list[i].len;
        else
            if(list[i].dir == list[(i+2)%6].dir)
                small*=list[(i+1)%6].len;
    cout<<(big-small)*n;
    return 0;
}