#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int a,b,aI=0,bI=0,dup=0;
    int A[200001],B[200001];
    scanf("%d %d",&a,&b);
    for(int i=0;i<a;i++)
        scanf("%d",&A[i]);
    for(int i=0;i<b;i++)
        scanf("%d",&B[i]);
    sort(A,A+a);sort(B,B+b);
    while(aI!=a && bI!=b){
        if(A[aI]==B[bI]){
            dup++;
            aI++;bI++;
        }
        else{
            if(A[aI]<B[bI])
                aI++;
            else
                bI++;
        }
    }
    cout<<a+b-dup*2;
    return 0;
}