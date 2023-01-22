#include<cstdio>
#include<algorithm>
using namespace std;
int n,arr[10002];
int main(){
    int loc=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        if(i && arr[i]>arr[i-1])
            loc=i;
    }
    if(!loc)
        printf("-1");
    else{
        next_permutation(arr,arr+n);
        for(int i=0;i<n;i++)
            printf("%d ",arr[i]);
    }
    return 0;
}