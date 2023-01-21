#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 1000002
#define DIV 1000000009
long long arr[MAX]={0,};
int main(){
    int t,n;
    scanf("%d",&t);
    arr[1]=1;arr[2]=2;arr[3]=4;
    for(int i=4;i<MAX;i++)
        arr[i]=(arr[i-1]+arr[i-2]+arr[i-3])%DIV;
    
    while(t--){
        scanf("%d",&n);
        printf("%d\n",arr[n]%DIV);
    }
    return 0;
}