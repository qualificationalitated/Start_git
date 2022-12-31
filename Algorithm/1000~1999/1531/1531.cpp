// prob. 1531
#include<iostream>
#include<cstdio>
using namespace std;
typedef struct
{
    int x;
    int y;
}grid;

int main()
{
    int n,m,ans=0;
    int paper[101][101]={0,};
    grid lb,rt,lt,rb; // left bottom , right top , left top, right bottom
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&lb.x, &lb.y, &rt.x, &rt.y);
        for(int j=lb.x;j<=rt.x;j++)
            for(int k=lb.y;k<=rt.y;k++)
                paper[j][k]++;
    }
    for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++)
            if(paper[i][j]>m) 
                ans++;
    printf("%d",ans);
    return 0;
}
/**
 * @brief 
 * n개의 종이로 가리기
 * but m개의 종이 이하로 올라가면 그림은 그 부분에서 보인다.
 * 보이지 않는 그림의 갯수를 세기
 * 
 */