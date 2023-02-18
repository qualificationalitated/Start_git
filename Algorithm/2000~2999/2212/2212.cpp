#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct sensor{ // 센서 정보 입력을 위한 구조체
    int loc;
    int nDist;
    sensor(int x, int y) : loc(x), nDist(y){}
};
bool cmpOrder(sensor x, sensor y){ // 오름차순 정렬 함수
    return x.loc<y.loc;
}
bool cmpMax(sensor x, sensor y){ // 최대 원소 위치 찾기용 함수
    return x.nDist<y.nDist;
}
vector<sensor> list;
int main(){
    int k,n,tmp,sum=0;
    cin>>k>>n;
    for(int i=0;i<k;i++){
        cin>>tmp;
        list.push_back(sensor(tmp,0));
    }
    sort(list.begin(),list.end(),cmpOrder); // 정렬

    for(int i=0;i<list.size()-1;i++)
        list[i].nDist = list[i+1].loc - list[i].loc; // 각 원소별로 다음거리 구해주고

    // n개의 수신기 중 n-1개를 멀리 떨어져있는 센서에 전담으로 붙이기
    tmp = n-1; 
    while(tmp--)
        list[max_element(list.begin(), list.end(),cmpMax) - list.begin()].nDist=0;
    
    // n-1개의 수신기를 통해 멀리 있던 센서들을 제거하고, 남은 센서들을 1개의 수신기로 묶어주기
    for(int i=0;i<list.size();i++)
        sum+=list[i].nDist;
    
    cout<<sum;
    return 0;
}