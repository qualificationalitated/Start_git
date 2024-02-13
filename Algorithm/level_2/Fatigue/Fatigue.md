# [피로도](https://school.programmers.co.kr/learn/courses/30/lessons/87946)

> 게임 내 각 던전마다는 탐험을 시작하기 위해 필요한 "최소 필요 피로도"와 던전 탐험을 마쳤을 때 소모되는 "소모 피로도"가 있습니다.  
> "최소 필요 피로도"는 해당 던전을 탐험하기 위해 가지고 있어야 하는 최소한의 피로도를 나타내며, "소모 피로도"는 던전을 탐험한 후 소모되는 피로도를 나타냅니다.  
> 유저의 현제 피로도K와, 하루에 한 번씩 탐험할 수 있는 던전들의 "최소 필요 피로도", "소모 피로도"가 담긴 2차원 배열 dungeons 가 매개변수로 주어집니다.  
> 이 때, 하루에 유저가 탐험할수 있는 최대 던전 수를 return 하도록 solution 함수를 완성해주세요.  

## 코드

```c++
#include <string>
#include <vector>

using namespace std;

bool visited[9];
int recursive(vector<vector<int>> dungeons,int currK,int cnt,int *ans){
    if(*ans < cnt) *ans = cnt;
    for(int i=0;i<dungeons.size();i++){
        if(visited[i] == false && currK >= dungeons[i][0]){
            visited[i] = true;
            recursive(dungeons,currK - dungeons[i][1],cnt+1,ans);
            visited[i] = false;
        }
    }
    return 0;
}
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    recursive(dungeons, k, 0,&answer);
    return answer;
}
```

## 풀이

재귀를 활용해 해결한 완전탐색 문제

recursive 함수를 만들어 방문 가능한 모든 경우의 수를 고려해 문제를 해결했다.  
최대한 전역변수 없이 문제를 해결하기 위해, 던전 목록, 플레이어의 현제 피로도, 방문한 던전 수, 답을 저장하기 위한 변수의 포인터를 함수의 인자로 활용했다.  
사실 return 값을 이용해 값을 저장하는 방식도 있는데, 구현 방법이 기억이 안나.. 조금은 비효율적으로 했다.  

이후 재귀적으로 프로그램이 진행되며 모든 던전 방문의 수를 고려하게 된다.  
한번의 재귀마다 모든 배열을 탐색하며, 조건에 맞는 경우(방문한 던전인지, 던전에 입장 가능한 피로도가 남아 있는지) 던전을 방문했다 체크하고 재귀적으로 함수를 호출해 배열에 방문한다.  
함수 종료 후 return 된 경우, 던전을 방문하지 않았던 경우로 판단해 방문했던 던전을 다시 방문 가능 상태로 설정한다.  
