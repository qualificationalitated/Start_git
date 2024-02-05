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