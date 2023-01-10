#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int solve(double x ,double y,double z){
    int low=0, high = 1000000000;
    if(x==y || z>=99)
        return -1;
    while(low<=high){
        int mid=(low+high)/2;
        int tmp = ((y+mid)*100)/(x+mid);
        if(z>=tmp)
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
}
int main(){
    double x,y;
    cin>>x>>y;
    cout<<solve(x,y,(y*100)/x);
    return 0;
}