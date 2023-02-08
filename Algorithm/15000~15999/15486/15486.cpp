#include<cstdio>
#include<algorithm>
using namespace std;
double list[1500001]={0,};
int main(){
    int n,t,p;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&t,&p);
        list[i+t] = max( list[i+t], list[i]+p);
        list[i+1] = max( list[i], list[i+1]);
    }
    printf("%.0lf",list[n+1]);
    return 0;
}