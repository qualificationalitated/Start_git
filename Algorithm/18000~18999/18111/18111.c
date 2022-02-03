#include<stdio.h>
int map[502][502]={0,};
int movement[2][502]={0,};//[0][x]x층에서 평탄화 시 채워야 할 블록의 갯수,[1][x]]x층에서 평탄화 시 제거해야할 블록의 갯수 
int main()
{
    int n,m,b,maxHeight=-1,minHeight=257,minTime=__INT_MAX__,loc;
    int dig,pillup,dc,pc,i,j;
    scanf("%d %d %d",&n,&m,&b);
    for (i=0;i<n;i++)
        for (j = 0; j < m; j++){// 지도 입력, 입력시 높이의 최대값과 최소값을 찾음
            scanf("%d",&map[i][j]);
            if(map[i][j]>maxHeight)
                maxHeight=map[i][j];
            if(map[i][j]<minHeight)
                minHeight=map[i][j];
        }
    for (int h=minHeight;h<=maxHeight;h++) // 찾은 높이의 최소값부터 최대값 순으로 올라가며 최소 시간을 계산함.
    {
        dig=0;
        pillup=0;
        dc=0;
        pc=0;
        for (i=0;i<n;i++)
            for (j=0;j<m;j++)//각 높이마다 현제 높이보다 높거나, 낮은 값들을 찾고 각각의 합과 갯수를 구함.
                if(h<map[i][j]){
                    dc++;
                    dig+=map[i][j];
                }
                else if(h>map[i][j]){
                    pc++;
                    pillup+=map[i][j];
                }
        dig=dig-(dc*h);//위 합을 바탕으로 각 높이에서 파내야 할 블럭과 메꿔야할 블럭의 갯수를 구함.
        pillup=(pc*h)-pillup;
        if(pillup<=b+dig)// 블럭을 채울때, 현제 가진 블럭과 파낸 블럭의 합만큼 내 블럭갯수가 있을때만 가능하도록 함.
        {
            if(minTime>=dig*2+pillup){
                minTime=dig*2+pillup;
                loc=h;
            }
        }
    }
    printf("%d %d",minTime,loc);
    return 0;
}