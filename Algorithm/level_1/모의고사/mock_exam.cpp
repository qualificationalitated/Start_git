#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    int pA[5]={1,2,3,4,5},pB[8]={2,1,2,3,2,4,2,5},pC[10]={3,3,1,1,2,2,4,4,5,5};
    int cntA=0,cntB=0,cntC=0,cntMax=0;
    vector<int> answer;
    for(int i=0;i<answers.size();i++){
        cntA+=(answers[i] == pA[i%5]);
        if(cntMax < cntA) cntMax = cntA;
        cntB+=(answers[i] == pB[i%8]);
        if(cntMax < cntB) cntMax = cntB;
        cntC+=(answers[i] == pC[i%10]);
        if(cntMax < cntC) cntMax = cntC;
    }
    if(cntMax == cntA) answer.push_back(1);
    if(cntMax == cntB) answer.push_back(2);
    if(cntMax == cntC) answer.push_back(3);
    return answer;
}