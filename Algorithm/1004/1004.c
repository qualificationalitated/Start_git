#include<stdio.h>
int distanceCheck(int ax,int ay,int bx,int by,int r)
{
    int n;
    n=(bx-ax)*(bx-ax)+(by-ay)*(by-ay);
    if(n<r*r)
    return 1;//close
    return 0;//far
}
int main()
{
    int t; //테스트케이스 수
    int sx,sy,ex,ey; // 시작, 끝 좌표
    int n; //별의 갯수
    int starX,starY,starR; // 별들의 좌표,반지름
    int count,sum=0;
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%d %d %d",&starX,&starY,&starR);
            sum+=distanceCheck(sx,sy,starX,starY,starR); // 반복적으로 거리체크 함수를 호출하지 않기위해, 추기적인 변수 사용
            sum+=distanceCheck(ex,ey,starX,starY,starR);
            if(sum<2){ //시작,끝점이 원 안에 함께 있는 경우를 제외하면,
                count+=sum;
            }
            sum=0;
        }
        printf("%d\n",count);
    }
    return 0;
}