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