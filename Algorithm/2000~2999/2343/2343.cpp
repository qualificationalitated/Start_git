#include<iostream>
#include<vector>
#define LIM 100001
using namespace std;
bool checker( vector<int> list, int limTime, int limCnt){
    int pSum=0,pCnt=0;
    bool result = true;
    for (int i = 0; i < list.size(); i++)
    {
        pSum+=list[i];
        if(pSum>limTime){
            pSum=0;
            pCnt++;
            i--;
        }
        if(pCnt>=limCnt){
            result = false;
            break;
        }
    }
    return result;
}
int main(){
    ios::sync_with_stdio;
    cin.tie(NULL);cout.tie(NULL);
    int n,m,sum=0,timeInput;
    vector<int> lecList;
    cin>>n>>m;
    for (int i = 0; i < n; i++){
        cin>>timeInput;
        sum+=timeInput;
        lecList.push_back(timeInput);
    }
    int head = 0, tail = sum;
    while(head<=tail){
        int estiLen = (head + tail) / 2;
        if(checker(lecList,estiLen,m))
            tail = estiLen-1;
        else
            head = estiLen+1;
    }
    cout<<head;
    return 0;
}