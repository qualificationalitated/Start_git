#include <stdio.h>
int main()
{
    int x1,x2,x3,y2,y1,y3;
    int r1u,r1d,r2u,r2d;
    scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
    if((x1*y2-x2*y1+x2*y3-x3*y2+x3*y1-x1*y3)/2>0)
        printf("1");
    else if((x1*y2-x2*y1+x2*y3-x3*y2+x3*y1-x1*y3)/2<0)
        printf("-1");
    else
        printf("0");
    return 0;
}
// 외적을 활용해 문제를 해결
// 벡터 A X 벡터 B = a*b*sin(t) -> 벡터 A를 기준으로 벡터 B가 회전하는 정보를 sin값으로 나타냄
// A x B 값의 음, 양, 0 여부는 sin값을 바탕으로 지정된다 이말이지
// -> 외적을 계산한 값이 0,-,+중 무엇인지 찾아 답을 출력하면 된다!
// 백터 계산을 하자...
// x1*y2-x2*y1 + x2*y3-x3*y2 + x3*y1-x1*y3 / 뭐 이렇게 된다고 한다.