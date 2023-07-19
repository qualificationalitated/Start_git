#include<iostream>
#include<algorithm>
#include<map> // 수가 백만개 들어오니, 맵으로 커버 가능
#include<queue>
using namespace std;
priority_queue<int,vector<int>,less<int>> max_pq; // 최대값 큐
priority_queue<int,vector<int>,greater<int>> min_pq; // 최소값 큐 
map<int,int> num_count;
void cleanQue(){
    while(!max_pq.empty() && !num_count[max_pq.top()])
        max_pq.pop();
    while(!min_pq.empty() && !num_count[min_pq.top()])
        min_pq.pop();
}
int main(){
    
    int t,k,num;
    char cmd;
    cin>>t;
    while(t--){
        while(!max_pq.empty()) // 최대값 큐 비우기
            max_pq.pop();
        while(!min_pq.empty()) // 최소값 큐 비우기
            min_pq.pop();
        num_count.clear(); // 맵 비우기
        cin>>k;
        while(k--){
            cin>>cmd>>num;
            if(cmd=='I'){ // 삽입
                max_pq.push(num);
                min_pq.push(num);
                num_count[num]++;
            }
            else {
                if(num==1){ // 최대값 삭제
                    if(!max_pq.empty()){
                        num_count[max_pq.top()]--;
                        max_pq.pop();
                    }
                }
                else{ // 최소값 삭제
                    if(!min_pq.empty()){
                        num_count[min_pq.top()]--;
                        min_pq.pop();
                    }
                }
                cleanQue();
            }
        }
        cleanQue();
        if(max_pq.empty() || min_pq.empty())
            cout<<"EMPTY\n";
        else
            cout<<max_pq.top()<<" "<<min_pq.top()<<"\n";
    }
    return 0;
}