#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int sumOfStr(string x){
    int tmp=0;
    for (int i = 0; i < x.length(); i++)
        if(x[i]>='0' && x[i]<='9') tmp+=(x[i]-'0');
    return tmp;
}
bool cmp(string x, string y){
    if(x.length() == y.length()){
        int xSum = sumOfStr(x);
        int ySum = sumOfStr(y);
        if(xSum == ySum)
            return (x.compare(y)<0)?1:0; // 수 같으면 사전순, compare함수 이용
        return xSum<ySum; // 길이 같으면 수가 작은게 앞으로
    }
    return x.length() < y.length(); // 짧은게 앞으로
}
int main(){
    int n;
    string input[51];
    cin>>n;
    for (int i = 0; i < n; i++)
        cin>>input[i];
    sort(input,input+n,cmp);
    for (int i = 0; i < n; i++)
        cout<<input[i]<<"\n";
    return 0;
}