# [같은 숫자는 싫어](https://school.programmers.co.kr/learn/courses/30/lessons/12906)

> 배열 arr가 주어집니다.  
> 배열 arr의 각 원소는 숫자 0부터 9까지로 이루어져 있습니다.  
> 이때, 배열 arr에서 연속적으로 나타나는 숫자는 하나만 남기고 전부 제거하려고 합니다.  
> 단, 제거된 후 남은 수들을 반환할 때는 배열 arr의 원소들의 순서를 유지해야 합니다.
>
> 배열 arr에서 연속적으로 나타나는 숫자는 제거하고 남은 수들을 return 하는 solution 함수를 완성해 주세요

## 코드

```c++
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    for(int i=0;i<arr.size();i++){
        answer.push_back(arr[i]);
        while(arr[i]==arr[i+1])
            i++;
    }
    return answer;
}
```

## 풀이

단순 구현 문제.

배열이 주어질 때, 최초 원소를 정답 반환을 위한 벡터에 넣은 뒤 동일 원소를 건너뛰는 작업을 진행한다.  
같지 않은 원소값이 나올 때 까지 while문을 통해 반복을 진행하는 식으로 동일 원소를 건너뛴다.
