# [모의고사](https://school.programmers.co.kr/learn/courses/30/lessons/42840)

> 수포자들은 일정 규칙을 활용해 주어진 문제의 정답을 모두 찍으려 한다.  
> 규칙은 아래와 같다.  
>
> - 1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...  
> - 2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
> - 3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...
>
> 1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.
>

## 코드

```c++
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
```

## 풀이

단순 구현문제 - 완전탐색

우선, 주어진 3명의 수포자 규칙을 배열로 정리한다.  
다음, 주어진 문제지의 정답을 순차적으로 탐색하는데, 이때 각 수포자 규칙의 길이로 나머지연산을 진행한다.  
또한, 이 과정에서 가장 많이 맞춘 사람의 정답 수를 기억한다.  
모든 탐색이 끝난다면, 참여자 3명과 가장 많이 맞춘 정답을 비교해 최다 정답자의 벡터를 만들어나간다.  
