#include<iostream>
#define MAX 202
using namespace std;
int ATot,BTot,CTot;
bool ans[MAX],is_used[MAX][MAX][MAX]={0,};
int make_combi(int A, int B, int C){
    if(is_used[A][B][C])   return 0; // 기존에 있는 조합은 리턴
    cout<<A<<" "<<B<<" "<<C<<"\n";
    is_used[A][B][C]=1;              // 사용 체크
    if(!A)  ans[C] = true;           // A 가 비어있을때 정답 체크
    
    int AAble = ATot-A, BAble = BTot-B,CAble = CTot-C; 
    if(C){ // C에 물 있으면
        // A에 채우기
        if(AAble>=C)    make_combi(A+C,B,0);
        else           make_combi(ATot,B,C-AAble);
        // B에 채우기
        if(BAble>=C)    make_combi(A,B+C,0);
        else           make_combi(A,BTot,C-BAble);
    }
    if(B){ // B에 물 있으면
        // A에 물 채우기
        if(AAble>=B)    make_combi(A+B,0,C);
        else           make_combi(ATot,B-AAble,C);
        // C에 물 채우기
        if(CAble>=B)    make_combi(A,0,C+B);
        else           make_combi(A,B-CAble,CTot);
    }
    if(A){ // A에 물 있으면
        // B에 물 채우기
        if(BAble>=A)    make_combi(0,B+A,C);
        else           make_combi(A-BAble,BTot,C);
        // C에 물 채우기
        if(CAble>=A)    make_combi(0,B,C+A);
        else           make_combi(A-CAble,B,CTot);
    }
    return 0;
}
int main(){
    cin>>ATot>>BTot>>CTot;
    for(int i=0;i<MAX;i++)  ans[i] = false;
    make_combi(0,0,CTot);
    for(int i=0;i<MAX;i++)
        if(ans[i]) cout<<i<<" ";
    return 0;
}