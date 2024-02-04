# [주식 가격](https://school.programmers.co.kr/learn/courses/30/lessons/42584)

> 초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때, 가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수를 완성하세요.  

## 코드

```c++
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    stack<pair<int,int>> stockPrices;
    int tempAnswer[100001]={0,};
    for(int i=0;i<prices.size();i++){
        pair<int,int> currPrice = make_pair(prices[i],i);
        while(!stockPrices.empty() && stockPrices.top().first>currPrice.first){
            tempAnswer[stockPrices.top().second] = currPrice.second - stockPrices.top().second;
            stockPrices.pop();
        }
        stockPrices.push(currPrice);
    }
    while(!stockPrices.empty()){
        tempAnswer[stockPrices.top().second] = prices.size()-1 - stockPrices.top().second;
        stockPrices.pop();
    }
    vector<int> answer;
    for(int i=0;i<prices.size();i++){
        answer.push_back(tempAnswer[i]);
    }
    return answer;
}

```

```c++
// clean code version

#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    stack<int> s;
    vector<int> answer(prices.size());
    for(int i=0;i<prices.size();i++){
        while(!s.empty() && prices[s.top()] > prices[i]){
            answer[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        answer[s.top()] = prices.size()-s.top()-1;
        s.pop();
    }
    return answer;
}
```

## 풀이

스택을 활용한 문제.

사실 보다 간단하게 푸는 방법이 있지만(2번째 코드).. 그 방법을 몰랐기에 복잡하게 풀었다.  
주어진 가격들을 stack에 넣으며, 이때 특정 시간과, 해당 시간의 주식 값을 쌍으로 저장한다.  
stack에 값을 넣을때는 stack의 top 에 위치한 가격 값이 넣고자 하는 원소의 가격 값보다 작은지 비교해, 작으면 넣고 크면 빼는 과정을 반복 한 후 원소를 넣는다.  
이 과정에서 원소가 pop 될경우, 현제 넣고자 하는 원소의 순서(prices에서 몇번째로 값이 들어오는지)와 pop 되는 원소의 순서간 차이를 활용해 주식 가격이 내려가지 않았던 시간을 계산한다.  
모든 원소에 대한 push작업이 완료되었다면, 스택에 남아있는 모든 원소는 그 즉시 pop 되어야하므로, 마지막 시간과 pop 되는 원소의 순서를 활용해 남아있는 원소들의 지속 가격 상승 시간을 확인한다.  

사실.. prices 벡터가 인자로 넘어왔다는점, 또한 이를 함수 내에서 접근할 수 있다는 점에서 가격과 순서, 둘 중 순서 하나의 값만을 stack으로 관리하는게 더 효율적이다.  
따라서, 아래 깔끔한 코드 버전과 같이 푸는게.. 더 좋다.
