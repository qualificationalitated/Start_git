# [카펫](https://school.programmers.co.kr/learn/courses/30/lessons/42842)

> Leo는 카펫을 사러 갔다가 아래 그림과 같이 중앙에는 노란색으로 칠해져 있고 테두리 1줄은 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.  
> Leo가 본 카펫에서 갈색 격자의 수 brown, 노란색 격자의 수 yellow가 매개변수로 주어질 때 카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.  
> 이때, 카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 깁니다.

## 코드

```c++
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {

    int size = brown + yellow;
    vector<int> answer;
    for(int hei=1 ; hei<=sqrt(size) ; hei++){
        int wid = size / hei;
        if(hei*wid == size){
            if(2*hei + 2*wid - 4 == brown){
                if((hei-2)*(wid-2) == yellow){
                    answer.push_back(wid);
                    answer.push_back(hei);
                    break;
                }
            }
        }
    }
    return answer;
}
```

## 풀이

단순 구현문제 - 완전탐색

주어진 카펫 타일의 수를 모두 더해 카펫의 전체 넓이를 구한다.  
이후, 세로보다 가로가 더 길다는 점을 이용해 넓이의 제곱근만큼 반복 탐색하며 너비와 높이 값을 탐색합니다.  
이후, 가로 세로의 크기가 주어진 갈색, 노란색 타일의 수와 맞는지 확인한 후, 가장 먼저 찾은 답을 answer에 넣고 반복을 멈춥니다.
반복 없이도 수학적 공식을 이용해 풀 수 있습니다. - 저는 실패입니다.  
