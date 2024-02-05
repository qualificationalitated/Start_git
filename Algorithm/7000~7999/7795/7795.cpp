#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int a,b,answer = 0;
        cin>>a>>b;
        int arrA[a+1],numB;
        for(int i=0;i<a;i++)
            cin>>arrA[i];
        sort(arrA,arrA+a); // 기본 오름차순
        for(int i=0;i<b;i++){
            cin>>numB;
            int head = 0, tail = a-1;
            while(head <= tail){
                int mid = (head + tail) / 2;
                if(numB < arrA[mid])
                    tail = mid - 1;
                else
                    head = mid + 1;
            }
            answer+=a-1-tail;
        }
        cout<<answer<<"\n";
    }
    return 0;
}