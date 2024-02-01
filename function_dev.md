# [기능개발](https://school.programmers.co.kr/learn/courses/30/lessons/12906)

> 프로그래머스 팀에서는 기능 개선 작업을 수행 중입니다.  
> 각 기능은 진도가 100%일 때 서비스에 반영할 수 있습니다.  
> 또, 각 기능의 개발속도는 모두 다르기 때문에 뒤에 있는 기능이 앞에 있는 기능보다 먼저 개발될 수 있고, 이때 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포됩니다.  
> 먼저 배포되어야 하는 순서대로 작업의 진도가 적힌 정수 배열과 각 작업의 개발 속도가 적힌 정수 배열이 주어질 때 각 배포마다 몇 개의 기능이 배포되는지를 return 하도록 solution 함수를 완성하세요.

## 코드

```c++
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
```

## 풀이

단순 구현 문제.

우선 각 작업마다 작업을 완료하는데 걸리는 모든 시간을 계산해 벡터로 구성한다.  
이후, 만들어진 벡터를 탐색하며 1회 배포시 얼마만큼의 기능이 배포되는지 계산한다.  
이때 탐색의 범위가 전제 작업 수를 넘지 않도록 주의하며, 작업이 완료되었으나 앞선 작업이 완료되지 않아 배포가 이뤄지지 않은 작업들의 수를 체크한다.  
체크한 작업들의 수를 answer 벡터에 저장한 후, 답을 리턴한다.  

더욱 좋은 방법으로, 반복문을 하나로 줄여 구현하는 방법 또한 있다.  
