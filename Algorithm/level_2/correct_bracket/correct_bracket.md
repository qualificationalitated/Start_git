# [올바른 괄호](https://school.programmers.co.kr/learn/courses/30/lessons/12909)

> 괄호가 바르게 짝지어졌다는 것은 '(' 문자로 열렸으면 반드시 짝지어서 ')' 문자로 닫혀야 한다는 뜻입니다.  
> '(' 또는 ')' 로만 이루어진 문자열 s가 주어졌을 때, 문자열 s가 올바른 괄호이면 true를 return 하고, 올바르지 않은 괄호이면 false를 return 하는 solution 함수를 완성해 주세요.

## 코드

```c++
#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int check = 0;
    for(char x : s){
        switch(x){
            case '(':
                check++;
                break;
            case ')':
                check--;
                break;
            default:
                break;
        }
        if(check<0)
            answer = false;
    }
    if(answer && check)
        answer = false;

    return answer;
}
```

## 풀이

단순 구현 문제.

스택의 개념을 학습하기 위한 문제로, 스택 헤더를 include해 풀수도 있지만 더 쉬운 방법으로 이를 처리한다.  
0으로 초기화 된 임의 변수 check를 만들어, 여는 괄호와 닫는 괄호의 들어오는 순서 및 양을 확인한다.  
여는 괄호가 들어오는경우 check값을 증가, 닫는 괄호가 들어오는 경우 check의 값을 감소시킨다.  
문자열이 끝나지 않았으나 check의 값이 음수로 떨어진경우, 여는 괄호보다 닫는 괄호가 앞서 나옴을 의미하며, 이는 잘못된 괄호로 처리한다.  
또한, 모든 입력이 끝났음에도 check의 값이 0이 아닌경우, 닫는 괄호나 여는 괄호 둘 중 하나가 더 많이 들어온것이므로, 잘못된 괄호로 처리한다.  
