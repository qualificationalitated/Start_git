#include<iostream>
#include<string>

using namespace std;
int main(){
    ios::sync_with_stdio;
    cin.tie(NULL);
    cout.tie(NULL);
    string n,temp;
    int currN = 0,index = 0;
    bool notFound = true;
    cin>>n;
    while(index < n.size()){
        currN++;
        temp = to_string(currN);
        for (int i = 0; i < temp.size(); i++)
            if(n[index] == temp[i])
                index++;
    }
    cout<<currN;
    return 0;
}