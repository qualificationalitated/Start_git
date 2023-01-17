#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,num,num_height[1002]={0,},ans=1;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&num);
        int max=0;
        // 앞선 값들중 최대값 찾기
        for(int i=1;i<num;i++)
            max=max<num_height[i]?num_height[i]:max;
        // 최대값 + 1 배열에 넣기 & 출력 예정값과 비교해 갱신하기
        num_height[num]=max+1;
        if(max+1 > ans)
            ans=max+1;
    }
    printf("%d",ans);
    return 0;
}