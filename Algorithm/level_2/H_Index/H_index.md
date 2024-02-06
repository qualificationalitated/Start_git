# [H-Index](https://school.programmers.co.kr/learn/courses/30/lessons/42747)

> 어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 이 과학자의 H-Index입니다.  
> 어떤 과학자가 발표한 논문의 인용 횟수를 담은 배열 citations가 매개변수로 주어질 때, 이 과학자의 H-Index를 return 하도록 solution 함수를 작성해주세요.

## 코드

```c++
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    for(int i=0;i<citations.size();i++){
        if(citations.size()-i<=citations[i]){
            answer = citations.size()-i;
            break;
        }
    }
    return answer;
}
```

## 풀이

정렬 문제

주어진 배열을 오름차순으로 정렬한 후, 순차적으로 탐색하며 (배열 크기 - 각 배열 인덱스)값과 비교를 진행한다.  
이는 곧 해당 인덱스의 값(인용수)과 같거나 더 많이 인용된 논문의 수를 의미하며, 논문의 인용수가 더 많아지기 시작하는 특정 지점에 남아있는 논문의 수가 이와 같거나 더 작다면, H index를 남아있는 논문의 수(배열 크기 - 각 배열 인덱스)로 설정하고 답을 리턴하면 된다.

이진탐색으로 접근할수도 있는 문제이다.(논문 출판 수의 범위인 0~10000을 활용해)
