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

/*
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
*/