#include<iostream>
using namespace std;
int main(){
    int L, P, V;
    int count=0,total_day=0;
    while(1){
        total_day=0;
        cin>>L>>P>>V;
        if(L==0 && P==0 && V==0)
            break;
        count++;
        total_day += (V/P) * L;
        total_day += (V%P) > L ? L : (V%P);
        cout<<"Case "<<count<<": "<<total_day<<"\n";
    }
    return 0;
}