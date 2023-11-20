#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    string name[2] = {"SK", "CY"};
    cin>>n;
    cout<<name[n%2];
    return 0;
}