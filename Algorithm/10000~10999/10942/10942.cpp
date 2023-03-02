#include<cstdio>
#define LIM 2002
using namespace std;
bool dp[LIM][LIM]={0,};
int input[LIM];
int dp_init(int x){
    for(int i=0;i<=x;i++)   // 같으면 초기화
        dp[i][i]=1;
    for(int i=0;i<=x-1;i++) // 길이 2일때 초기화
        if(input[i] == input[i+1])
            dp[i][i+1] = 1;
    return 0;
}
int main(){
    int n,m;int s,e;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&input[i]);
    dp_init(n);
    for(int i=n-1;i>=1;i--)
        for(int j=i+1;j<=n;j++)
            if(input[i] == input[j] && dp[i+1][j-1])
                dp[i][j]=1;
    scanf("%d",&m);
    while(m--){
        scanf("%d %d",&s,&e);
        printf("%d\n",dp[s][e]);
    }
    return 0;
}