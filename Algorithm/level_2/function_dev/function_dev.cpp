#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int cpl=0,head=0;
    vector<int> answer,workdays;
    
    for(int i=0;i<progresses.size();i++){
        double temp = (100 - progresses[i]) / (double)speeds[i];
        workdays.push_back(ceil(temp));
    }
    while(head<workdays.size()){
        cpl = 1;
        while(workdays[head] >= workdays[head+cpl] && head + cpl<progresses.size())
            cpl++;
        head += cpl;
        answer.push_back(cpl);
    }
    return answer;
}