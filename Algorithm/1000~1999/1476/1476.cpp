#include<iostream>
using namespace std;
int main(){
    int earth, sun, moon, date = 0;
    cin>>earth>>sun>>moon;
    while(((date % 15) + 1 != earth ) || ((date % 28) + 1 != sun ) || ((date % 19) + 1 != moon ))
        date++;
    cout<<date+1;
    return 0;
}