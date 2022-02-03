#include<stdio.h>
int hanoii(int n,int start,int waypoint,int destination){
    if(n==1){
        printf("%d %d\n",start,destination);
        return 0;
    }
    else{
        hanoii(n-1,start,destination,waypoint);
        printf("%d %d\n",start,destination);
        hanoii(n-1,waypoint,start,destination);
        return 0;
    }
    return 0;
}
int main()
{
    int n,rep=1;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        rep*=2;
    printf("%d\n",rep-1);
    hanoii(n,1,2,3);
    return 0;
}
/*
하노이 탑
어쩃거나, 저쨋거나, 1번칸에 있는 N개의 블록을 3번으로 보내자!
그러려면, 1번칸의 맨 아래에 있는 블록을 3번으로 옮기는게 먼저다!
그러려면 그러려면, 맨 마지막 칸 위 블록들을 2번칸으로 옯기고,
마지막 블록을 3번으로 옮기고,
다시금 2번칸의 블록들을 3번으로 옮기자!
잠깐, 그럼.
처음에 2번으로 옮기는 블록은 어떻게 옮김?
그건이제, 1번칸에서 2번으로 두번쨰 작은 블록(N-1번째 블록)을 옮겨야 하니까,
1번에서 N-2개만큼의 블록을 3번으로 옮기고
N-1번쨰 블록을 2번으로 옮기고,
3번째 칸에 있는 N-2블록들을 2번으로 옮기자.

->
옮기기 총 3단계로 구성.
위에꺼 날리기,
맨 아래꺼 옮기기
위에꺼 다시 들고 오기
1,3번을 간다고 하면, 2번을 경유지로 설정해서 사용
*/