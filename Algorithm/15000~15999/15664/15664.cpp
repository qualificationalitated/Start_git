#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 10002
int n,m,arr[10],ans[10];
int select(int len,int loc){
    if(len==m){
        for(int i=0;i<m;i++)
            printf("%d ",ans[i]);
        printf("\n");
        return 0;
    }
    for(int i=loc;i<n;i++){
        ans[len]=arr[i];
        select(len+1,i+1);
        while(arr[i]==arr[i+1]) i++;
    }
    return 0;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    select(0,0);
    return 0;
}