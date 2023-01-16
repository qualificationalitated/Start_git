#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cmp(int x, int y){
    return x>y;
}
int main(){
    int n,arr[10002]={0,},loc=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        if(i&&i<n&&arr[i-1]>arr[i]) // 오름차순이 반전되는 마지막 구간의 위치 찾기
            loc=i;
    }
    if(!loc) // 반전 구간이 없으면, 이전 수열이 없다고 판단
        printf("-1");
    else{
        int j=n-1; 
        // 반전수열이 시작되는 위치의 수와, 배열 내 다른 수들을 뒤에서부터 비교
        // 배열 내 다른 수가 반전 수열의 시작 수보다 "작아지는" 위치 탐색
        while(arr[loc-1]<arr[j])
            j--;
        // 둘 바꿔주고, 반전 수열위치부터 내림차순으로 정렬
        swap(arr[loc-1],arr[j]);
        sort(arr+loc,arr+n,cmp);
        for(int i=0;i<n;i++)
            printf("%d ",arr[i]);
    }
    return 0;
}

// #include<iostream>
// #include<cstdio>
// #include<algorithm>
// using namespace std;
// int main(){
//     int n,arr[10002]={0,},loc=0;
//     scanf("%d",&n);
//     for(int i=0;i<n;i++){
//         scanf("%d",&arr[i]);
//         if(i&&i<n&&arr[i-1]>arr[i])
//             loc=i;
//     }
//     if(!loc)
//         printf("-1");
//     else{
//         prev_permutation(arr,arr+n);
//         for(int i=0;i<n;i++)
//             printf("%d ",arr[i]);
//     }
//     return 0;
// }